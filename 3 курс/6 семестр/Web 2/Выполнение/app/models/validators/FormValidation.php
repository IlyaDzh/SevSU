<?php

class FormValidation {
    public $errors = [];
    public $rules = [
        'fullname' => [
			'isNotEmpty'
		],
        'group' => [
			'isNotEmpty'
		],
		'phone' => [
			'isNotEmpty',
			'isPhone'
		],
		'date' => [
			'isNotEmpty'
		],
		'Email' => [
			'isEmail'
        ],
        'message' => [
            'isNotEmpty'
        ],
        'review' => [
            'isNotEmpty'
        ],
        'title' => [
            'isNotEmpty'
        ]
    ];

    public function setRule($field_name, $validator_name) {
        if (!$this->rules[$field_name]) {
            $this->rules[$field_name] = [];
        }
        array_push($this->rules[$field_name], $validator_name);
	}

    public function getErrors() {
        return $this->errors;
    }

    public function validate($post_array) {
        foreach ($post_array as $key => $item) {
            if ($this->rules[$key]) {
                foreach ($this->rules[$key] as $rule) {
                    $this->$rule($item, $key);
                }
            }
        }
    }

    public function isNotEmptySelect($data, $key) {
		if ($data == 'Выберите ответ') {
			array_push($this->errors, "Поле Вопрос 2 не должно быть пустым");
		}
		return true;
    }

    public function isNotEmpty($data, $key) {
		if (empty($data)) {
            if ($key == "fullname") {
                $resultKey = "ФИО";
            } elseif ($key == "group") {
                $resultKey = "Группа";
            } elseif ($key == "message") {
                $resultKey = "Сообщение";
            } elseif ($key == "title") {
                $resultKey = "Тема";
            } elseif ($key == "review") {
                $resultKey = "Отзыв";
            } elseif ($key == "phone") {
                $resultKey = "Телефон";
            } elseif ($key == "date") {
                $resultKey = "Дата";
            } elseif ($key == "q3") {
                $resultKey = "Вопрос 3";
            }
			array_push($this->errors, "Поле $resultKey не должно быть пустым");
		}
		return true;
    }
    
    public function isInteger($data, $key = null, $value = null) {
		if (ctype_digit($data)) {
			array_push($this->errors, "Поле Вопрос 3 содержит числа");
		}
		return false;
    }
    
    public function isLess($data, $key, $value = null){
		if ($this->isInteger($data) && ((int)$this->isInteger($data) >= $value)) {
			array_push($this->errors, "Поле $key слишком длинное");
		}
		return true;
	}

	public function isGreater($data, $key, $value = null){
		if ($this->isInteger($data) && ((int)$this->isInteger($data) <= $value)) {
			array_push($this->errors, "Поле $key слишком короткое");
		}
		return true;
    }
    
    public function isEmail($data, $key, $value = null) {
		if (preg_match('/^((([0-9A-Za-z]{1}[-0-9A-z\.]{1,}[0-9A-Za-z]{1})|([0-9А-Яа-я]{1}[-0-9А-я\.]{1,}[0-9А-Яа-я]{1}))@([-A-Za-z]{1,}\.){1,2}[-A-Za-z]{2,})$/u', $data)) {
			return true;
		}
		array_push($this->errors, "В поле $key неверно введена почта");
	}

	public function isPhone($data, $key, $value = null) {
		if (preg_match('/^(\+7|\+3)([0-9]{8,10})$/', $data)) {
			return true;
		}
		array_push($this->errors, "В поле Телефон неверно введен номер телефона");
	}
}