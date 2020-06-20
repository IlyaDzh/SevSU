<?php

class MainController extends Controller {
	function indexAction() {	
		$this->view->render('MainView.php', 'Главная');
	}
}