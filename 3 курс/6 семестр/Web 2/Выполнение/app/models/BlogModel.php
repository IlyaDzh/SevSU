<?php

class BlogModel extends Model {
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

        $result = [
           "posts" => $posts,
           "current_page" => $currentPage, 
           "total_pages" => $totalPages 
        ];

        return $result;
    }
}