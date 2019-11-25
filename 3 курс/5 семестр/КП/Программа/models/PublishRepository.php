<?php

include "Publish.php";

class PublishRepository {
    protected $db;

    public function __construct(PDO $db) {
        $this->db = $db;
    }

    private function read($row) {
        $result = new Publish();
        $result->id = $row["id_издательства"];
        $result->name = $row["название"];
        $result->address = $row["адрес"];
        return $result;
    }

    public function getById($id) {
        $sql = "SELECT * FROM издательства WHERE id_издательства = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
        $rows = $q->fetchAll();
        return $this->read($rows[0]);
    }

    public function getAll($filter) {
        $id = $filter["id"];
        $name = "%" . $filter["name"] . "%";
        $address = "%" . $filter["address"] . "%";

        $sql = "SELECT * FROM издательства WHERE (:id = 0 OR id_издательства = :id) AND название LIKE :name AND адрес LIKE :address";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id);
        $q->bindParam(":name", $name);
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
        $sql = "INSERT INTO издательства (id_издательства, название, адрес) VALUES (:id, :name, :address)";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":name", $data["name"]);
        $q->bindParam(":address", $data["address"]);
        $q->execute();
        return $this->getById($this->db->lastInsertId());
    }

    public function update($data) {
        $sql = "UPDATE издательства SET id_издательства = :id, название = :name, адрес = :address WHERE id_издательства = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $data["id"], PDO::PARAM_INT);
        $q->bindParam(":name", $data["name"]);
        $q->bindParam(":address", $data["address"]);
        $q->execute();
    }

    public function remove($id) {
        $sql = "DELETE FROM издательства WHERE id_издательства = :id";
        $q = $this->db->prepare($sql);
        $q->bindParam(":id", $id, PDO::PARAM_INT);
        $q->execute();
    }
}

?>