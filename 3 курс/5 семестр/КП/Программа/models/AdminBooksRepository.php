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
        $id_categories = $filter["id_categories"];
        $id_publish = $filter["id_publish"];
        $date_create = "%" . $filter["date_create"] . "%";
        $number_pages = $filter["number_pages"];

        $sql = "SELECT * FROM книги
                WHERE (:id = 0 OR id_книги = :id) 
                AND название LIKE :name 
                AND (:id_categories = 0 OR id_направления = :id_categories) 
                AND (:id_publish = 0 OR id_издательства = :id_publish) 
                AND год_издания LIKE :date_create 
                AND (:number_pages = 0 OR количество_страниц = :number_pages)";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id);
        $q->bindParam(":name", $name);
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
        return $this->getById($this->db->lastInsertId());
    }

    public function update($data) {
        $sql = "UPDATE книги 
                SET id_книги = :id, название = :name, id_направления = :id_categories, id_издательства = :id_publish, год_издания = :date_create, количество_страниц = :number_pages 
                WHERE id_книги = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":name", $data["name"]);
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