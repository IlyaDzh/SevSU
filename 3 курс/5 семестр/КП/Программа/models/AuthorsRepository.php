<?php

include "Authors.php";

class AuthorsRepository {
    protected $db;

    public function __construct(PDO $db) {
        $this->db = $db;
    }

    private function read($row) {
        $result = new Authors();
        $result->id = $row["id_автора"];
        $result->name = $row["фио"];
        $result->degree = $row["учёная_степень"];
        $result->date = $row["дата_рождения"];
        return $result;
    }

    public function getById($id) {
        $sql = "SELECT * FROM авторы WHERE id_автора = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
        $rows = $q->fetchAll();
        return $this->read($rows[0]);
    }

    public function getAll($filter) {
        $id = $filter["id"];
        $name = "%" . $filter["name"] . "%";
        $degree = $filter["degree"];
        $date = "%" . $filter["date"] . "%";

        $sql = "SELECT * FROM авторы WHERE (:id = 0 OR id_автора = :id) AND фио LIKE :name AND (:degree = '' OR учёная_степень = :degree) AND дата_рождения LIKE :date";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id);
        $q->bindParam(":name", $name);
        $q->bindParam(":degree", $degree);
        $q->bindParam(":date", $date);
        $q->execute();
        $rows = $q->fetchAll();

        $result = array();
        foreach($rows as $row) {
            array_push($result, $this->read($row));
        }
        return $result;
    }

    public function insert($data) {
        $sql = "INSERT INTO авторы (id_автора, фио, учёная_степень, дата_рождения) VALUES (:id, :name, :degree, :date)";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":name", $data["name"]);
        $q->bindParam(":degree", $data["degree"]);
        $q->bindParam(":date", $data["date"]);
        $q->execute();
        return $this->getById($this->db->lastInsertId());
    }

    public function update($data) {
        $sql = "UPDATE авторы SET id_автора = :id, фио = :name, учёная_степень = :degree, дата_рождения = :date WHERE id_автора = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":name", $data["name"]);
        $q->bindParam(":degree", $data["degree"]);
        $q->bindParam(":date", $data["date"]);
        $q->execute();
    }

    public function remove($id) {
        $sql = "DELETE FROM авторы WHERE id_автора = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
    }
}

?>