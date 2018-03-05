<?php

class HrgpNode extends ForgelyNode {
    function parseFeed($feed)
    {
        parent::parseFeed($feed);


        if(!empty($feed['post_date'])) {
            $post_date = new DateTime($feed['post_date']);
            $this->raw()->created = $post_date->getTimestamp();
        }
    }
}