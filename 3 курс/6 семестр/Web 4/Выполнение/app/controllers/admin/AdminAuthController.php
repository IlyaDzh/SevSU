<?php

class AdminAuthController extends Controller {
	function indexAction() {
		$this->view->render('AdminAuthView.php', 'Вход', null, 'AdminLayoutView.php');
    }
    
    function loginAction() {
		if (!empty($_POST)) {
			$this->model->validator->validate($_POST);
            $errors = $this->model->validator->getErrors();

            if (empty($errors)) {
                if ($this->compareLoginData($_POST)) {
                    header('Location:/admin/editblog');
                    exit;
                } else {
                    $login = false;
                    $_POST['password'] = null;
                }
            }

            $vars = [ 'errors' => $errors, 'login' => $login ];

			$this->view->render('AdminAuthView.php', 'Вход', $vars, 'AdminLayoutView.php');
		} else {
            $this->view->render('AdminAuthView.php', 'Вход', null, 'AdminLayoutView.php');
        }
    }

    function logoutAction() {
        unset($_SESSION['isAdmin']);
        header('Location:/admin/auth');
        exit;
    }
    
    function compareLoginData($post_array) {
        if (($post_array['login'] === 'admin') && (md5($post_array['password']) === 'e10adc3949ba59abbe56e057f20f883e')) {
            $_SESSION['isAdmin'] = 1;
            return true; 
        } 
        return false;
    }
}