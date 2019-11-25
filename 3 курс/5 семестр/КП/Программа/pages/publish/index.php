<?php

include "../../models/PublishRepository.php";

$config = include("../../db/config.php");
$db = new PDO($config["db"], $config["username"], $config["password"]);
$publish = new PublishRepository($db);

switch($_SERVER["REQUEST_METHOD"]) {
    case "GET":
        $result = $publish->getAll(array(
            "id" => intval($_GET["id"]),
            "name" => $_GET["name"],
            "address" => $_GET["address"]
        ));
        break;

    case "POST":
        $result = $publish->insert(array(
            "id" => intval($_POST["id"]),
            "name" => $_POST["name"],
            "address" => $_POST["address"]
        ));
        break;

    case "PUT":
        parse_str(file_get_contents("php://input"), $_PUT);

        $result = $publish->update(array(
            "id" => intval($_PUT["id"]),
            "name" => $_PUT["name"],
            "address" => $_PUT["address"]
        ));
        break;

    case "DELETE":
        parse_str(file_get_contents("php://input"), $_DELETE);

        $result = $publish->remove(intval($_DELETE["id"]));
        break;
}

header("Content-Type: application/json");
echo json_encode($result);

?>