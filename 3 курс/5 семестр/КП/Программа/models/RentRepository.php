<?php

include "Rent.php";

class RentRepository {
    protected $db;

    public function __construct(PDO $db) {
        $this->db = $db;
    }

    private function read($row) {
        $result = new Rent();
        $result->id = $row["id_выдачи"];
        $result->books = $row["название_книги"]; 
        $result->readers = $row["читатели"]; 
        $result->date_rent = $row["дата_выдачи"];
        $result->date_return = $row["дата_возврата"];
        return $result;
    }

    public function getById($id) {
        $sql = "SELECT * FROM выдача_книг WHERE id_выдачи = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
        $rows = $q->fetchAll();
        return $this->read($rows[0]);
    }

    // SELECT выдача_книг.id_выдачи, книги.название, читатели.фио, выдача_книг.дата_выдачи, выдача_книг.дата_возврата
    // FROM выдача_книг
    // JOIN книги ON выдача_книг.id_книги = книги.id_книги
    // JOIN читатели ON выдача_книг.id_читателя = читатели.id_читателя
    // ORDER BY выдача_книг.id_выдачи ASC

    public function getAll($filter) {
        $id = $filter["id"];
        $name = "%" . $filter["name"] . "%";
        $date = "%" . $filter["date"] . "%";
        $gender = "%" . $filter["gender"] . "%";
        $tel = "%" . $filter["tel"] . "%";
        $address = "%" . $filter["address"] . "%";

        $sql = "SELECT * FROM выдача_книг WHERE (:id = 0 OR id_читателя = :id) AND фио LIKE :name AND дата_рождения LIKE :date AND (:gender = 0 OR пол = :gender) AND телефон LIKE :tel AND адрес LIKE :address";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id);
        $q->bindParam(":name", $name);
        $q->bindParam(":date", $date);
        $q->bindParam(":gender", $gender);
        $q->bindParam(":tel", $tel);
        $q->bindParam(":address", $address);
        $q->execute();
        $rows = $q->fetchAll();

        $result = array();
        foreach($rows as $row) {
            array_push($result, $this->read($row));
        }
        return $result;
    }

    public function insert($data) {
        $sql = "INSERT INTO выдача_книг (id_читателя, фио, дата_рождения, пол, телефон, адрес) VALUES (:id, :name, :date, :gender, :tel, :address)";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":name", $data["name"]);
        $q->bindParam(":date", $data["date"]);
        $q->bindParam(":gender", $data["gender"]);
        $q->bindParam(":tel", $data["tel"]);
        $q->bindParam(":address", $data["address"]);
        $q->execute();
        return $this->getById($this->db->lastInsertId());
    }

    public function update($data) {
        $sql = "UPDATE выдача_книг SET id_читателя = :id, фио = :name, дата_рождения = :date, пол = :gender, телефон = :tel, адрес = :address WHERE id_читателя = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":name", $data["name"]);
        $q->bindParam(":date", $data["date"]);
        $q->bindParam(":gender", $data["gender"]);
        $q->bindParam(":tel", $data["tel"]);
        $q->bindParam(":address", $data["address"]);
        $q->execute();
    }

    public function remove($id) {
        $sql = "DELETE FROM выдача_книг WHERE id_читателя = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
    }
}

?>