<?php

class HistoryController extends Controller {
	function indexAction() {	
		$this->view->render('HistoryView.php', 'История');
	}
}