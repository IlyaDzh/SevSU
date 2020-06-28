<?php

require_once "app/core/AdminController.php";

class AdminStatisticsController extends AdminController {
    function __construct() {
		$this->model = new AdminStatisticsModel();
		$this->view = new View();
    }

	function indexAction() {
        $this->checkIsAuth();
        $result = $this->model->getStatistics($_GET);
		$this->view->render('AdminStatisticsView.php', 'Статистика посещений', $result, 'AdminLayoutView.php');
    }
}