<?php

include "Categories.php";

class CategoriesRepository {
    protected $db;

    public function __construct(PDO $db) {
        $this->db = $db;
    }

    private function read($row) {
        $result = new Categories();
        $result->id = $row["id_направления"];
        $result->description = $row["описание"];
        return $result;
    }

    public function getById($id) {
        $sql = "SELECT * FROM направления WHERE id_направления = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
        $rows = $q->fetchAll();
        return $this->read($rows[0]);
    }

    public function getAll($filter) {
        $id = $filter["id"];
        $description = "%" . $filter["description"] . "%";

        $sql = "SELECT * FROM направления WHERE (:id = 0 OR id_направления = :id) AND описание LIKE :description";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id);
        $q->bindParam(":description", $description);
        $q->execute();
        $rows = $q->fetchAll();

        $result = array();
        foreach($rows as $row) {
            array_push($result, $this->read($row));
        }
        return $result;
    }

    public function insert($data) {
        $sql = "INSERT INTO направления (id_направления, описание) VALUES (:id, :description)";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":description", $data["description"]);
        $q->execute();
        return $this->getById($this->db->lastInsertId());
    }

    public function update($data) {
        $sql = "UPDATE направления SET id_направления = :id, описание = :description WHERE id_направления = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":description", $data["description"]);
        $q->execute();
    }

    public function remove($id) {
        $sql = "DELETE FROM направления WHERE id_направления = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
    }
}

?>