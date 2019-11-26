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
        $result->readers = $row["фио_читателя"]; 
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

    public function getAll($filter) {
        $id = $filter["id"];
        $books = "%" . $filter["books"] . "%";
        $readers = "%" . $filter["readers"] . "%";
        $date_rent = "%" . $filter["date_rent"] . "%";
        $date_return = "%" . $filter["date_return"] . "%";

        $sql = "SELECT выдача_книг.id_выдачи, книги.название 'название_книги', читатели.фио 'фио_читателя', выдача_книг.дата_выдачи, выдача_книг.дата_возврата
                FROM выдача_книг
                JOIN книги ON выдача_книг.id_книги = книги.id_книги
                JOIN читатели ON выдача_книг.id_читателя = читатели.id_читателя
                WHERE (:id = 0 OR id_выдачи = :id) AND книги.название LIKE :books AND читатели.фио LIKE :readers AND выдача_книг.дата_выдачи LIKE :date_rent AND выдача_книг.дата_возврата LIKE :date_return
                ORDER BY выдача_книг.id_выдачи ASC";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id);
        $q->bindParam(":books", $books);
        $q->bindParam(":readers", $readers);
        $q->bindParam(":date_rent", $date_rent);
        $q->bindParam(":date_return", $date_return);
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
        $q->bindParam(":books", $data["books"]);
        $q->bindParam(":readers", $data["readers"]);
        $q->bindParam(":date_rent", $data["date_rent"]);
        $q->bindParam(":date_return", $data["date_return"]);
        $q->execute();
        return $this->getById($this->db->lastInsertId());
    }

    public function update($data) {
        $sql = "UPDATE выдача_книг SET id_читателя = :id, фио = :name, дата_рождения = :date, пол = :gender, телефон = :tel, адрес = :address WHERE id_читателя = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":books", $data["books"]);
        $q->bindParam(":readers", $data["readers"]);
        $q->bindParam(":date_rent", $data["date_rent"]);
        $q->bindParam(":date_return", $data["date_return"]);
        $q->execute();
    }

    public function remove($id) {
        $sql = "DELETE FROM выдача_книг WHERE id_выдачи = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
    }
}

?>