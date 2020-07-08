<?php

class AdminStatisticsModel extends Model {
    public function __construct() {
        parent::__construct();
        static::$tablename = 'statistics';
        static::$dbfields = array('page', 'ip', 'host', 'browser', 'date');
    }

    public function getStatistics($get_array) {
        $countOfPosts = $this->getCount();
        $rowsPerPage = 6;
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

        $statistics = $this->findByPage($offset, $rowsPerPage);

        $result = [
           "statistics" => $statistics,
           "current_page" => $currentPage, 
           "total_pages" => $totalPages 
        ];

        return $result;
    }
}