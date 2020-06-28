<?php

class Route {
	static function start() {
		$controller_name = 'Main';
		$action_name = 'index';
		
		$routes = explode('/', $_SERVER['REQUEST_URI']);

		if ($routes[1] == "admin") {
            if (!empty($routes[2])) {	
                $controller_name = $routes[2];
            }
            if (!empty($routes[3])) {
                $action_name = $routes[3];
            }
            $admin_prefix = "Admin";
            $admin_path = "admin/";
        } else {
            if (!empty($routes[1])) {	
                $controller_name = $routes[1];
            }
            if (!empty($routes[2])) {
                $action_name = $routes[2];
            }
        }

		$model_name = $admin_prefix . $controller_name . 'Model';
		$controller_name = $admin_prefix . $controller_name . 'Controller';
		$action_name = $action_name . 'Action';

		$model_file = $model_name . '.php';
		$model_path = "app/models/". $admin_path . $model_file;
		if (file_exists($model_path)) {
			include $model_path;
		}

		$controller_file = $controller_name . '.php';
		$controller_path = "app/controllers/". $admin_path . $controller_file;
		if (file_exists($controller_path)) {
			include $controller_path;
		} else {
            Route::ErrorPage404();
		}
		
		$controller = new $controller_name;
		$action = $action_name;
		
		if (method_exists($controller, $action)) {
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