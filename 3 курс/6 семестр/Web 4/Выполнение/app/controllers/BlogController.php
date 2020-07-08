<?php

class BlogController extends Controller {
    function __construct() {
		$this->model = new BlogModel();
		$this->view = new View();
    }

	function indexAction() {
        $this->model->saveUserInfo("Мой блог");
        $result = $this->model->getPosts($_GET);
		$this->view->render('BlogView.php', 'Мой блог', $result);
    }

    function addAction() {
        $this->model->addComment($_GET);
        $json = [
            'id' => $_GET['id_post'], 
            'fullname' => $_GET['fullname'], 
            'comment' => $_GET['comment'], 
            'date' => $_GET['date']
        ];
        echo "addComment(".json_encode($json).");";
    }
}