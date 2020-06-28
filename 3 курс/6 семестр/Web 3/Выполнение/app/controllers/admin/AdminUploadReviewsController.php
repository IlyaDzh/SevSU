<?php

require_once "app/core/AdminController.php";

class AdminUploadReviewsController extends AdminController {
	function indexAction() {	
        $this->checkIsAuth();
		$this->view->render('AdminUploadReviewsView.php', 'Загрузка отзывов', null, 'AdminLayoutView.php');
    }
    
    function createAction() {
        $this->checkIsAuth();
        if ($_FILES['file']['name'] != "") {
            if (copy ($_FILES['file']['tmp_name'], 'reviews.inc')) {
                $vars = [ 'result' => true ];
            } else {
                $vars = [ 'error' => true ];
            }
            $this->view->render('AdminUploadReviewsView.php', 'Загрузка отзывов', $vars, 'AdminLayoutView.php');
        } else {
            $vars = [ 'empty' => true ];
            $this->view->render('AdminUploadReviewsView.php', 'Загрузка отзывов', $vars, 'AdminLayoutView.php');
        }
	}
}