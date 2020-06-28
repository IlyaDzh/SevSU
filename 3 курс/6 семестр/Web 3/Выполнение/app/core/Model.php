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

    public function saveUserInfo($page) {
		static::setupConnection();

		$tablename = 'statistics';
		$sql = "
            INSERT INTO $tablename (`page`, `ip`, `host`, `browser`, `date`) 
            VALUES (
                '" . $page . "', 
                '" . $_SERVER['REMOTE_ADDR'] . "', 
                '" . gethostbyaddr($_SERVER['REMOTE_ADDR']) . "', 
                '" . $_SERVER['HTTP_USER_AGENT'] . "',
                '" . date('Y-m-d H:i:s') . "'
            )
        ";
		$stmt = static::$pdo->query($sql);
	}
}