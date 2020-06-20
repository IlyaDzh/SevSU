<?php

class BlogController extends Controller {
    function __construct() {
		$this->model = new BlogModel();
		$this->view = new View();
    }

	function indexAction() {
        $result = $this->model->getPosts($_GET);
		$this->view->render('BlogView.php', 'Мой блог', $result);
    }
}