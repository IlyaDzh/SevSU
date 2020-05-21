<?php

class ErrorController extends Controller {
	function indexAction() {	
		$this->view->render('ErrorView.php', 'Ошибка');
	}
}