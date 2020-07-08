<?php

class AboutController extends Controller {
	function indexAction() {	
        $this->model->saveUserInfo("Обо мне");
		$this->view->render('AboutView.php', 'Обо мне');
	}
}