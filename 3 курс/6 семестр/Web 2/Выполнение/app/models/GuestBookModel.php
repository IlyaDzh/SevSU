<?php

class GuestBookModel extends Model {
    public function parseReviews() {
        $arrStr = file("reviews.inc");
        $reviews = [];
        foreach (array_reverse($arrStr) as $str) {
            array_push($reviews, preg_split('/;/', $str));
        }

        return $reviews;
    }

    public function addReview($data) {
        $file = fopen('reviews.inc', 'a+');

        foreach($data as $item) {
            $str .= $item . ';';
        }

        fwrite($file, "$str\n");
        fclose($file);
    }
}