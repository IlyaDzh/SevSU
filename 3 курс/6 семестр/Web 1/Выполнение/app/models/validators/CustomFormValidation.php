<?php

class CustomFormValidation extends FormValidation {
    public function __construct() {
        $this->setRule('Вопрос_2', 'isNotEmptySelect');
        $this->setRule('Вопрос_3', 'isNotEmpty'); 
        $this->setRule('Вопрос_3', 'isInteger');
    }
}