<?php

require_once "app/core/AdminController.php";

class AdminUploadPostsController extends AdminController {
    function __construct() {
		$this->model = new AdminUploadPostsModel();
		$this->view = new View();
    }

	function indexAction() {	
        $this->checkIsAuth();
		$this->view->render('AdminUploadPostsView.php', 'Загрузка постов блога', null, 'AdminLayoutView.php');
    }
    
    function createAction() {
        $this->checkIsAuth();
        if ($_FILES['file']['name'] != "") {
            if ($this->model->savePosts($_FILES)) {
                $vars = [ 'result' => true ];
            } else {
                $vars = [ 'error' => true ];
            }
            $this->view->render('AdminUploadPostsView.php', 'Загрузка постов блога', $vars, 'AdminLayoutView.php');
        } else {
            $vars = [ 'empty' => true ];
            $this->view->render('AdminUploadPostsView.php', 'Загрузка постов блога', $vars, 'AdminLayoutView.php');
        }
	}
}