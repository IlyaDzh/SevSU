<?php

class TestController extends Controller {
    function __construct() {
		$this->model = new TestModel();
		$this->view = new View();
    }
    
	function indexAction() {	
		$this->view->render('TestView.php', 'Тест');
    }
    
    function checkAction() {
		if (!empty($_POST)) {
			$this->model->validator->validate($_POST);
            $errors = $this->model->validator->getErrors();
			if (empty($errors)) {
                $this->model->validator->checkAns($_POST);
                $this->model->createTest($_POST);
                $_POST = array();
                $result = $this->model->validator->getResult();
                $vars = [ 'result' => $result ];
			}
			else {
                $vars = [ 'errors' => $errors ];
            }
			$this->view->render('TestView.php', 'Тест', $vars);
		} else {
            $this->view->render('TestView.php', 'Тест');
        }
	}
}