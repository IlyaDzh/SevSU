<?php

class HistoryController extends Controller {
	function indexAction() {	
        $this->model->saveUserInfo("История");
		$this->view->render('HistoryView.php', 'История');
	}
}