<?php

class AdminController extends Controller {
    function checkIsAuth() {
        if (!isset($_SESSION['isAdmin'])) {
            header('Location:/admin/auth');
            exit;
        }
    }
}
  