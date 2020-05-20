<?php

class TestController extends Controller {
	function indexAction() {	
		$this->view->render('TestView.php', 'Тест');
	}
}