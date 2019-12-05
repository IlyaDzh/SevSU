<?php

include "AdminBooks.php";

class AdminBooksRepository {
    protected $db;

    public function __construct(PDO $db) {
        $this->db = $db;
    }

    private function read($row) {
        $result = new AdminBooks();
        $result->id = $row["id_книги"];
        $result->name = $row["название"];
        $result->id_authors = $row["id_авторов"];
        $result->id_categories = $row["id_направления"];
        $result->id_publish = $row["id_издательства"];
        $result->date_create = $row["год_издания"];
        $result->number_pages = $row["количество_страниц"];
        return $result;
    }

    public function getById($id) {
        $sql = "SELECT * FROM книги WHERE id_книги = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
        $rows = $q->fetchAll();
        return $this->read($rows[0]);
    }

    public function getAll($filter) {
        $id = $filter["id"];
        $name = "%" . $filter["name"] . "%";
        $id_authors = $filter["id_authors"];
        $id_categories = $filter["id_categories"];
        $id_publish = $filter["id_publish"];
        $date_create = "%" . $filter["date_create"] . "%";
        $number_pages = $filter["number_pages"];

        $sql = "SELECT книги.id_книги, книги.название, 
                    GROUP_CONCAT(distinct авторы_книги.id_автора SEPARATOR ', ') as id_авторов, 
                    книги.id_направления, книги.id_издательства, книги.год_издания, книги.количество_страниц 
                FROM книги
                LEFT JOIN авторы_книги ON авторы_книги.id_книги = книги.id_книги
                WHERE (:id = 0 OR книги.id_книги = :id) 
                    AND книги.название LIKE :name 
                    AND (:id_authors = '' OR авторы_книги.id_автора = :id_authors) 
                    AND (:id_categories = 0 OR книги.id_направления = :id_categories) 
                    AND (:id_publish = 0 OR книги.id_издательства = :id_publish) 
                    AND книги.год_издания LIKE :date_create 
                    AND (:number_pages = 0 OR книги.количество_страниц = :number_pages)
                    GROUP BY книги.id_книги";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id);
        $q->bindParam(":name", $name);
        $q->bindParam(":id_authors", $id_authors);
        $q->bindParam(":id_categories", $id_categories);
        $q->bindParam(":id_publish", $id_publish);
        $q->bindParam(":date_create", $date_create);
        $q->bindParam(":number_pages", $number_pages);
        $q->execute();
        $rows = $q->fetchAll();

        $result = array();
        foreach($rows as $row) {
            array_push($result, $this->read($row));
        }
        return $result;
    }

    public function insert($data) {
        $sql = "INSERT INTO книги (id_книги, название, id_направления, id_издательства, год_издания, количество_страниц) 
                VALUES (:id, :name, :id_categories, :id_publish, :date_create, :number_pages)";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":name", $data["name"]);
        $q->bindParam(":id_categories", $data["id_categories"], PDO::PARAM_INT);
        $q->bindParam(":id_publish", $data["id_publish"], PDO::PARAM_INT);
        $q->bindParam(":date_create", $data["date_create"]);
        $q->bindParam(":number_pages", $data["number_pages"], PDO::PARAM_INT);
        $q->execute();

        $idAuthors = explode(",", str_replace(" ", "", $data["id_authors"]));
        foreach($idAuthors as $arr){
            $this->insertAuthors($arr, $data["name"]);
        }
        
        return $this->getById($this->db->lastInsertId());
    }

    public function insertAuthors($arr, $authorsName) {
        $sql = "INSERT INTO авторы_книги (id_книги, id_автора)
                SELECT книги.id_книги, :id_authors
                FROM книги
                WHERE книги.название = :name";
        $q = $this->db->prepare($sql);
        $q->bindParam(":name", $authorsName);
        $q->bindParam(":id_authors", $arr, PDO::PARAM_INT);
        $q->execute();
    }

    public function update($data) {
        $sql = "UPDATE книги 
                SET id_книги = :id, название = :name, id_направления = :id_categories, id_издательства = :id_publish, год_издания = :date_create, количество_страниц = :number_pages 
                WHERE id_книги = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":name", $data["name"]);
        $q->bindParam(":id_authors", $data["id_authors"]);
        $q->bindParam(":id_categories", $data["id_categories"], PDO::PARAM_INT);
        $q->bindParam(":id_publish", $data["id_publish"], PDO::PARAM_INT);
        $q->bindParam(":date_create", $data["date_create"]);
        $q->bindParam(":number_pages", $data["number_pages"], PDO::PARAM_INT);
        $q->execute();
    }

    public function remove($id) {
        $sql = "DELETE FROM книги WHERE id_книги = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
    }
}

?>