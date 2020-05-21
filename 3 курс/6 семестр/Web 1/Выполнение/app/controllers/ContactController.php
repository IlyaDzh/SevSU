<?php

class ContactController extends Controller {
	function indexAction() {	
		$this->view->render('ContactView.php', 'Контакт');
    }
    
    function checkAction() {
		if (!empty($_POST)) {
			$this->model->validator->validate($_POST);
            $errors = $this->model->validator->getErrors();
            $vars = [ 'errors' => $errors ];
			$this->view->render('ContactView.php', 'Контакт', $vars);
		} else {
            $this->view->render('ContactView.php', 'Контакт');
        }
	}
}