<?php

class AdminEditBlogModel extends Model {
    public function __construct() {
        parent::__construct();
        static::$tablename = 'blog';
        static::$dbfields = array('title', 'image', 'text', 'date');
    }

    public function getPosts($get_array) {
        $countOfPosts = $this->getCount();
        $rowsPerPage = 3;
        $totalPages = ceil($countOfPosts / $rowsPerPage);

        if (isset($get_array['page']) && is_numeric($get_array['page'])) {
            $currentPage = (int) $get_array['page'];
        } else {
            $currentPage = 1;
        }

        if ((int) $currentPage > (int) $totalPages) {
            $currentPage = $totalPages;
        }

        if ((int) $currentPage < 1) {
            $currentPage = 1;
        }

        $offset = ($currentPage - 1) * $rowsPerPage;

        $posts = $this->findByPage($offset, $rowsPerPage);

        $comments = [];
        foreach ($posts as $post) {
            $sql = "SELECT * FROM `comments` WHERE `id_post`=".$post['id']." ORDER BY `date` DESC";
            array_push($comments, $this->executeSQL($sql));
		}

        $result = [
           "posts" => $posts,
           "comments" => $comments,
           "current_page" => $currentPage, 
           "total_pages" => $totalPages 
        ];

        return $result;
    }

    public function addPost($post_array, $files_array) {
        if ($files_array["file"]["size"] > 0) {
            $timestamp = date_timestamp_get(date_create());
            $this->saveImageInFolder($files_array, $timestamp);
            $data = [
                "title" => $post_array["title"],
                "image" => "uploads/" . $timestamp . "_" . $files_array["file"]["name"],
                "text" => $post_array["message"]
            ];
        } else {
            $data = [
                "title" => $post_array["title"],
                "image" => NULL,
                "text" => $post_array["message"]
            ];
        }
        array_push($data, date('Y-m-d H:i:s'));

        $this->save($data);
    }

    public function editPost($post_array) {
        $sql = "
            UPDATE `blog` 
            SET 
                `title` = '".$post_array["title"]."', 
                `text` = '".$post_array["message"]."'
            WHERE 
                `id` = '".$post_array["id"]."'
        ";
        $this->executeSQL($sql);
    }

    private function saveImageInFolder($files_array, $timestamp) {
        $uploadDir = 'uploads/';
        $uploadFile = $uploadDir . $timestamp . "_" . basename($files_array['file']['name']);
        move_uploaded_file($files_array['file']['tmp_name'], $uploadFile);
    }
}