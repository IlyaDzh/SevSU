<?php

class AuthModel extends Model {
    public function __construct() {
        parent::__construct();
        static::$tablename = 'users';
        static::$dbfields = array('fullname', 'email', 'login', 'password');
    }

    public function createUser($post_array) {
        $findUserByEmail = $this->findByField($post_array['Email'], 'email');
        $findUserByLogin = $this->findByField($post_array['login'], 'login');

		if ($findUserByEmail != null || $findUserByLogin != null) {
			return false;
        }
        
        $data = [
			"fullname" => $post_array["fullname"],
			"email" => $post_array['Email'],
			"login" => $post_array["login"],
			"password" => $post_array["password"]
        ];

        $this->save($data);
        return true;
    }

    public function findUser($post_array) {
        $user = $this->findByQuery("`login`='".$post_array['login']."' AND `password`='".$post_array['password']."'");

		if ($user == null) {
			return false;
        }

        return $user;
    }
}