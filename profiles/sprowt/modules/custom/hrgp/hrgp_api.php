<?php

require_once drupal_get_path('module', 'hrgp') . '/hrgp_node.php';

class HrgpApiException extends Exception {
    public function __construct($message = "", $code = 0, Throwable $previous = null)
    {
        parent::__construct($message, $code, $previous);
    }
}

class HrgpApi extends ForgelyApi {

    private $xml_url = '';
    private $api_method;
    private $org_name;


    function __construct()
    {
        $this->xml_url = variable_get('hrgp_api_url', '');
        $this->api_method = variable_get('hrgp_api_method', 'xml_url');
        $this->org_name = variable_get('hrgp_api_orgname', '');
    }

    /**
     * @return string
     */
    public function getXmlUrl()
    {
        return $this->xml_url;
    }

    /**
     * @param string $xml_url
     */
    public function setXmlUrl($xml_url)
    {
        $this->xml_url = $xml_url;
    }
    
    /**
     * @return null
     */
    public function getOrgName() {
        return $this->org_name;
    }
    
    /**
     * @param null $org_name
     */
    public function setOrgName($org_name) {
        $this->org_name = $org_name;
    }

    function getDataRaw() {
        switch($this->api_method) {
            case 'xml_url':
                return $this->getDataXmlURL();
                break;
            case 'soap_api':
                return $this->getDataApi();
                break;
        }
    }
    
    function getDataApi() {
        $org = $this->org_name;
        $soap = new SoapClient('https://www.hrgp.co/AdvancedWidget.asmx?WSDL');
        
        $result = $soap->ReturnJobs(array(
            'strOrgName' => $org
        ));
        
        $xml = (string) $result->ReturnJobsResult;
        
        return $this->convertXml($xml);
    }
    
    function convertXml($xml = '') {
        if(empty($xml)) {
            watchdog('HRGP API', 'Url returns empty: !url', array('!url' => $this->xml_url), WATCHDOG_WARNING);
            return array(
                'data' => array()
            );
        }
    
        $jobs = new SimpleXMLElement($xml);
        $data = array();
        foreach($jobs->Job as $job) {
            $datum = array();
            $datum['jobId'] = (string)$job->referencenumber;
            $datum['title'] = (string)$job->title;
            $datum['description'] = html_entity_decode((string)$job->description);
            $datum['teaser'] = null;
            $datum['benefits'] = null;
            $datum['employment_types'] = null;
            $datum['salary_range'] = null;
            $datum['category'] = null;
            $location = array(
                'name' => (string)$job->city,
                'address' => null,
                'city' => (string)$job->city,
                'state' => (string)$job->state,
                'zip' => (string)$job->zipcode,
                'phone' => null,
                'altphone' => null,
                'emailAddress' => null
            );
        
            $datum['location'] = $location;
            $datum['application_link'] = (string)$job->url;
            $datum['post_date'] = (string)$job->post_date;
            $data[] = $datum;
        }
    
        return array(
            'success' => true,
            'data' => $data
        );
    }
    
    function getDataXmlURL() {
        if(empty($this->xml_url)) {
            return array(
                'success' => false,
                'data' => array()
            );
        }
    
        $xml = @file_get_contents($this->xml_url);
    
        return $this->convertXml($xml);
        
    }

    function getData() {
        $preserve = md5('preserve field');
        $data = $this->getDataRaw();
        foreach($data['data'] as &$item) {
            $item['teaser'] = $preserve;
            $item['benefits'] = $preserve;
            $item['employment_types'] = $preserve;
            $item['salary_range'] = $preserve;
            $item['category'] = $preserve;
        }

        return $data;
    }

    function syncData($feed) {
        foreach ($feed as $job) {
            $node = new HrgpNode($job);

            try {
                $do_not_delete = $node->field_do_not_delete->value();
                if(empty($do_not_delete)) {
                    $node->save();
                }
            }
            catch(NodeBuilderException $e) {
                watchdog_exception('Hrgp', $e);
            }
        }
    }
}