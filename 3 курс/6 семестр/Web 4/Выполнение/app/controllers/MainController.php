<?php

class MainController extends Controller {
	function indexAction() {	
        $this->model->saveUserInfo("Главная");
		$this->view->render('MainView.php', 'Главная');
	}
}