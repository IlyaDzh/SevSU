<?php

require 'app/models/validators/ResultsVerification.php';

class TestModel extends Model {
    public $validator;

    public function __construct() {
        $this->validator = new ResultsVerification();
        static::$tablename = 'test';
        static::$dbfields = array('fullname', 'question_1', 'question_2', 'question_3', 'count', 'date');
    }

    public function createTest($post_array) {
        $checkboxes = array_filter([
            $post_array["checkbox1"],
            $post_array["checkbox2"],
            $post_array["checkbox3"]
        ]);
        $checkboxesWithComma = implode(', ', $checkboxes);

        $result = $this->validator->getResult();

        $data = [
			"fullname" => $post_array["fullname"],
			"question_1" => $checkboxesWithComma,
			"question_2" => $post_array["q2"],
			"question_3" => $post_array["q3"],
            "count" => $result
        ];
        array_push($data, date('d.m.Y'));

        $this->save($data);
    }
}