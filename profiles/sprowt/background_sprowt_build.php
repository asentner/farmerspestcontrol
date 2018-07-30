<?php

/**
 * Utility class for HHVM/PHP environment handling.
 *
 * From here: https://raw.githubusercontent.com/sebastianbergmann/environment/master/src/Runtime.php
 *
 */
final class Runtime
{
    /**
     * @var string
     */
    private static $binary;

    /**
     * Returns true when Xdebug is supported or
     * the runtime used is PHPDBG.
     */
    public function canCollectCodeCoverage()
    {
        return $this->hasXdebug() || $this->hasPHPDBGCodeCoverage();
    }

    /**
     * Returns true when OPcache is loaded and opcache.save_comments=0 is set.
     *
     * Code taken from Doctrine\Common\Annotations\AnnotationReader::__construct().
     */
    public function discardsComments()
    {
        if (\extension_loaded('Zend Optimizer+') && (\ini_get('zend_optimizerplus.save_comments') === '0' || \ini_get('opcache.save_comments') === '0')) {
            return true;
        }

        if (\extension_loaded('Zend OPcache') && \ini_get('opcache.save_comments') == 0) {
            return true;
        }

        return false;
    }

    /**
     * Returns the path to the binary of the current runtime.
     * Appends ' --php' to the path when the runtime is HHVM.
     */
    public function getBinary()
    {
        // HHVM
        if (self::$binary === null && $this->isHHVM()) {
            // @codeCoverageIgnoreStart
            if ((self::$binary = \getenv('PHP_BINARY')) === false) {
                self::$binary = PHP_BINARY;
            }

            self::$binary = \escapeshellarg(self::$binary) . ' --php' .
                ' -d hhvm.php7.all=1';
            // @codeCoverageIgnoreEnd
        }

        if (self::$binary === null && PHP_BINARY !== '') {
            self::$binary = \escapeshellarg(PHP_BINARY);
        }

        if (self::$binary === null) {
            // @codeCoverageIgnoreStart
            $possibleBinaryLocations = [
                PHP_BINDIR . '/php',
                PHP_BINDIR . '/php-cli.exe',
                PHP_BINDIR . '/php.exe'
            ];

            foreach ($possibleBinaryLocations as $binary) {
                if (\is_readable($binary)) {
                    self::$binary = \escapeshellarg($binary);
                    break;
                }
            }
            // @codeCoverageIgnoreEnd
        }

        if (self::$binary === null) {
            // @codeCoverageIgnoreStart
            self::$binary = 'php';
            // @codeCoverageIgnoreEnd
        }

        return self::$binary;
    }

    public function getNameWithVersion()
    {
        return $this->getName() . ' ' . $this->getVersion();
    }

    public function getName()
    {
        if ($this->isHHVM()) {
            // @codeCoverageIgnoreStart
            return 'HHVM';
            // @codeCoverageIgnoreEnd
        }

        if ($this->isPHPDBG()) {
            // @codeCoverageIgnoreStart
            return 'PHPDBG';
            // @codeCoverageIgnoreEnd
        }

        return 'PHP';
    }

    public function getVendorUrl()
    {
        if ($this->isHHVM()) {
            // @codeCoverageIgnoreStart
            return 'http://hhvm.com/';
            // @codeCoverageIgnoreEnd
        }

        return 'https://secure.php.net/';
    }

    public function getVersion()
    {
        if ($this->isHHVM()) {
            // @codeCoverageIgnoreStart
            return HHVM_VERSION;
            // @codeCoverageIgnoreEnd
        }

        return PHP_VERSION;
    }

    /**
     * Returns true when the runtime used is PHP and Xdebug is loaded.
     */
    public function hasXdebug()
    {
        return ($this->isPHP() || $this->isHHVM()) && \extension_loaded('xdebug');
    }

    /**
     * Returns true when the runtime used is HHVM.
     */
    public function isHHVM()
    {
        return \defined('HHVM_VERSION');
    }

    /**
     * Returns true when the runtime used is PHP without the PHPDBG SAPI.
     */
    public function isPHP()
    {
        return !$this->isHHVM() && !$this->isPHPDBG();
    }

    /**
     * Returns true when the runtime used is PHP with the PHPDBG SAPI.
     */
    public function isPHPDBG()
    {
        return PHP_SAPI === 'phpdbg' && !$this->isHHVM();
    }

    /**
     * Returns true when the runtime used is PHP with the PHPDBG SAPI
     * and the phpdbg_*_oplog() functions are available (PHP >= 7.0).
     *
     * @codeCoverageIgnore
     */
    public function hasPHPDBGCodeCoverage()
    {
        return $this->isPHPDBG();
    }
}

$base = getcwd();
$script = $base . '/BackgroundBuilder.php';

$dir = sys_get_temp_dir();
$outputfile = $dir . '/sprowtoutput.log';
$pidfile = $dir . '/sprowtpid';

$rt = new Runtime();
$php = $rt->getBinary();
$php = str_replace('php-fpm', 'php', $php);

$cmd = $php . ' ' . $script;
$cmdFull = sprintf("%s > %s 2>&1 & echo $! >> %s", $cmd, $outputfile, $pidfile);

if(!empty($_GET['XDEBUG_SESSION_START'])) {
    $cmdFull = "export XDEBUG_CONFIG=\"idekey=willmcmillian\"; $cmdFull; unset XDEBUG_CONFIG";
}

//from here: https://stackoverflow.com/a/45966/5873687
exec($cmdFull, $out);

echo json_encode(array(
    'out' => $out,
    'cmdFull' => $cmdFull,
    'cmd' => $cmd,
    'base' => $base,
    'outputfile' => $outputfile,
    'pidfile' => $pidfile
));