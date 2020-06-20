<?php

class HobbyController extends Controller {
	function __construct() {
		$this->model = new HobbyModel();
		$this->view = new View();
	}
	
	function indexAction() {
		$data = $this->model->get_data();		
		$this->view->render('HobbyView.php', 'Мои интересы', $data);
	}
}