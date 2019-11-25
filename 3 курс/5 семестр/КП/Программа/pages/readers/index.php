<?php

include "../../models/ReadersRepository.php";

$config = include("../../db/config.php");
$db = new PDO($config["db"], $config["username"], $config["password"]);
$readers = new ReadersRepository($db);

switch($_SERVER["REQUEST_METHOD"]) {
    case "GET":
        $result = $readers->getAll(array(
            "id" => intval($_GET["id"]),
            "name" => $_GET["name"],
            "date" => $_GET["date"],
            "gender" => $_GET["gender"],
            "tel" => $_GET["tel"],
            "address" => $_GET["address"]
        ));
        break;

    case "POST":
        $result = $readers->insert(array(
            "id" => intval($_POST["id"]),
            "name" => $_POST["name"],
            "date" => $_POST["date"],
            "gender" => $_POST["gender"],
            "tel" => $_POST["tel"],
            "address" => $_POST["address"]
        ));
        break;

    case "PUT":
        parse_str(file_get_contents("php://input"), $_PUT);

        $result = $readers->update(array(
            "id" => intval($_PUT["id"]),
            "name" => $_PUT["name"],
            "date" => $_PUT["date"],
            "gender" => $_PUT["gender"],
            "tel" => $_PUT["tel"],
            "address" => $_PUT["address"]
        ));
        break;

    case "DELETE":
        parse_str(file_get_contents("php://input"), $_DELETE);

        $result = $readers->remove(intval($_DELETE["id"]));
        break;
}

header("Content-Type: application/json");
echo json_encode($result);

?>