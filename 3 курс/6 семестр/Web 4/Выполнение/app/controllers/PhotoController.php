<?php

class PhotoController extends Controller {
	function __construct() {
		$this->model = new PhotoModel();
		$this->view = new View();
	}
	
	function indexAction() {
        $this->model->saveUserInfo("Фотоальбом");
		$data = $this->model->get_data();		
		$this->view->render('PhotoView.php', 'Фотоальбом', $data);
	}
}