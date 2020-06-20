<?php

class GuestBookController extends Controller {
    function __construct() {
		$this->model = new GuestBookModel();
		$this->view = new View();
    }

	function indexAction() {	
        $reviews = $this->model->parseReviews();	
        $vars = [ 'reviews' => $reviews ];	
		$this->view->render('GuestBookView.php', 'Гостевая книга', $vars);
    }
    
    function createAction() {
		if (!empty($_POST)) {
			$this->model->validator->validate($_POST);
            $errors = $this->model->validator->getErrors();

            if (empty($errors)) {
                $newReview = [];
                array_push($newReview, $_POST['fullname'], $_POST['Email'], date('Y-m-d H:i:s'), $_POST['review']);
                $this->model->addReview($newReview);
                $_POST = array();
            }

            $reviews = $this->model->parseReviews();	
            $vars = [ 'errors' => $errors, 'reviews' => $reviews ];

			$this->view->render('GuestBookView.php', 'Гостевая книга', $vars);
		} else {
            $this->view->render('GuestBookView.php', 'Гостевая книга');
        }
	}
}