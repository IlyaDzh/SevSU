<?php

class StudiesController extends Controller {
	function indexAction() {	
        $this->model->saveUserInfo("Учеба");
		$this->view->render('StudiesView.php', 'Учеба');
	}
}