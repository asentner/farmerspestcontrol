<?php

/**
 * This code was generated by
 * \ / _    _  _|   _  _
 * | (_)\/(_)(_|\/| |(/_  v1.0.0
 * /       /
 */

namespace Twilio\Rest\Sync\V1\Service;

use Twilio\Options;
use Twilio\Values;

/**
 * PLEASE NOTE that this class contains beta products that are subject to change. Use them with caution.
 */
abstract class SyncListOptions {
    /**
     * @param string $uniqueName The unique_name
     * @return CreateSyncListOptions Options builder
     */
    public static function create($uniqueName = Values::NONE) {
        return new CreateSyncListOptions($uniqueName);
    }
}

class CreateSyncListOptions extends Options {
    /**
     * @param string $uniqueName The unique_name
     */
    public function __construct($uniqueName = Values::NONE) {
        $this->options['uniqueName'] = $uniqueName;
    }

    /**
     * The unique_name
     * 
     * @param string $uniqueName The unique_name
     * @return $this Fluent Builder
     */
    public function setUniqueName($uniqueName) {
        $this->options['uniqueName'] = $uniqueName;
        return $this;
    }

    /**
     * Provide a friendly representation
     * 
     * @return string Machine friendly representation
     */
    public function __toString() {
        $options = array();
        foreach ($this->options as $key => $value) {
            if ($value != Values::NONE) {
                $options[] = "$key=$value";
            }
        }
        return '[Twilio.Sync.V1.CreateSyncListOptions ' . implode(' ', $options) . ']';
    }
}