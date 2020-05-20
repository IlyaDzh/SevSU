<?php

class ContactController extends Controller {
	function indexAction() {	
		$this->view->render('ContactView.php', 'Контакт');
	}
}