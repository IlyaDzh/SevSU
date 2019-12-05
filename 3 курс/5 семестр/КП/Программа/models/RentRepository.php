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
        $result->id_books = $row["id_книги"]; 
        $result->id_readers = $row["id_читателя"]; 
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
        $id_books = $filter["id_books"];
        $id_readers = $filter["id_readers"];
        $date_rent = "%" . $filter["date_rent"] . "%";
        $date_return = "%" . $filter["date_return"] . "%";

        $sql = "SELECT * FROM выдача_книг
                WHERE (:id = 0 OR id_выдачи = :id) 
                    AND (:id_books = 0 OR id_книги = :id_books) 
                    AND (:id_readers = 0 OR id_читателя = :id_readers) 
                    AND дата_выдачи LIKE :date_rent 
                    AND дата_возврата LIKE :date_return";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id);
        $q->bindParam(":id_books", $id_books);
        $q->bindParam(":id_readers", $id_readers);
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
        $sql = "INSERT INTO выдача_книг (id_выдачи, id_книги, id_читателя, дата_выдачи, дата_возврата) 
                VALUES (:id, :id_books, :id_readers, :date_rent, :date_return)";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":id_books", $data["id_books"], PDO::PARAM_INT);
        $q->bindParam(":id_readers", $data["id_readers"], PDO::PARAM_INT);
        $q->bindParam(":date_rent", $data["date_rent"]);
        $q->bindParam(":date_return", $data["date_return"]);
        $q->execute();
        return $this->getById($this->db->lastInsertId());
    }

    public function update($data) {
        $sql = "UPDATE выдача_книг 
                SET id_выдачи = :id, id_книги = :id_books, id_читателя = :id_readers, дата_выдачи = :date_rent, дата_возврата = :date_return 
                WHERE id_выдачи = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":id_books", $data["id_books"], PDO::PARAM_INT);
        $q->bindParam(":id_readers", $data["id_readers"], PDO::PARAM_INT);
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