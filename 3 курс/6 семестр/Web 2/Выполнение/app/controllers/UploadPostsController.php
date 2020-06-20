<?php

class UploadPostsController extends Controller {
    function __construct() {
		$this->model = new UploadPostsModel();
		$this->view = new View();
    }

	function indexAction() {	
		$this->view->render('UploadPostsView.php', 'Загрузка постов блога');
    }
    
    function createAction() {
        if ($_FILES['file']['name'] != "") {
            if ($this->model->savePosts($_FILES)) {
                $vars = [ 'result' => true ];
            } else {
                $vars = [ 'error' => true ];
            }
            $this->view->render('UploadPostsView.php', 'Загрузка постов блога', $vars);
        } else {
            $vars = [ 'empty' => true ];
            $this->view->render('UploadPostsView.php', 'Загрузка постов блога', $vars);
        }
	}
}