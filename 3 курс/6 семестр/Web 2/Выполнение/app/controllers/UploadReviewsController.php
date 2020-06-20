<?php

class UploadReviewsController extends Controller {
	function indexAction() {	
		$this->view->render('UploadReviewsView.php', 'Загрузка отзывов');
    }
    
    function createAction() {
        if ($_FILES['file']['name'] != "") {
            if (copy ($_FILES['file']['tmp_name'], 'reviews.inc')) {
                $vars = [ 'result' => true ];
            } else {
                $vars = [ 'error' => true ];
            }
            $this->view->render('UploadReviewsView.php', 'Загрузка отзывов', $vars);
        } else {
            $vars = [ 'empty' => true ];
            $this->view->render('UploadReviewsView.php', 'Загрузка отзывов', $vars);
        }
	}
}