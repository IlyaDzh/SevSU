<?php

require 'app/models/validators/FormValidation.php';
require_once 'app/core/BaseActiveRecord.php';

class Model extends BaseActiveRecord {
    public $validator;

    function __construct() {
        $this->validator = new FormValidation();
    }

    public function get_data() { }

    public function validate($post_data) {
        $this->validator->validate($post_data);
    }
}