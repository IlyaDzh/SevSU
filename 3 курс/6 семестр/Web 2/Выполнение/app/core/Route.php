<?php

class Route {
	static function start() {
		// контроллер и действие по умолчанию
		$controller_name = 'Main';
		$action_name = 'index';
		
		$routes = explode('/', $_SERVER['REQUEST_URI']);

		// получаем имя контроллера
		if (!empty($routes[1])) {	
			$controller_name = $routes[1];
		}
		
		// получаем имя экшена
		if (!empty($routes[2])) {
			$action_name = $routes[2];
		}

		// добавляем префиксы
		$model_name = $controller_name . 'Model';
		$controller_name = $controller_name . 'Controller';
		$action_name = $action_name . 'Action';

		// подцепляем файл с классом модели
		$model_file = $model_name . '.php';
		$model_path = "app/models/" . $model_file;
		if (file_exists($model_path)) {
			include "app/models/" . $model_file;
		}

		// подцепляем файл с классом контроллера
		$controller_file = $controller_name . '.php';
		$controller_path = "app/controllers/" . $controller_file;
		if (file_exists($controller_path)) {
			include "app/controllers/" . $controller_file;
		} else {
            Route::ErrorPage404();
		}
		
		// создаем контроллер
		$controller = new $controller_name;
		$action = $action_name;
		
		if (method_exists($controller, $action)) {
			// вызываем действие контроллера
			$controller->$action();
		} else {
            Route::ErrorPage404();
		}
	
	}
	
	function ErrorPage404() {
        $host = 'http://' . $_SERVER['HTTP_HOST'] . '/';
		header('Location:' . $host.'error');
    }
}