<?php

class StudiesController extends Controller {
	function indexAction() {	
		$this->view->render('StudiesView.php', 'Учеба');
	}
}