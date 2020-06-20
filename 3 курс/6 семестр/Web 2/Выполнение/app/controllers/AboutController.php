<?php

class AboutController extends Controller {
	function indexAction() {	
		$this->view->render('AboutView.php', 'Обо мне');
	}
}