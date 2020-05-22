<?php

require 'app/models/validators/ResultsVerification.php';

class TestModel extends Model {
    public function __construct() {
        parent::__construct($validator);
        $this->validator = new ResultsVerification();
    }
}