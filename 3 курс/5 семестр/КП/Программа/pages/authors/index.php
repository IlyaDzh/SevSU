<?php

include "../../models/AuthorsRepository.php";

$config = include("../../db/config.php");
$db = new PDO($config["db"], $config["username"], $config["password"]);
$authors = new AuthorsRepository($db);

switch($_SERVER["REQUEST_METHOD"]) {
    case "GET":
        $result = $authors->getAll(array(
            "id" => intval($_GET["id"]),
            "name" => $_GET["name"]
        ));
        break;

    case "POST":
        $result = $authors->insert(array(
            "id" => intval($_POST["id"]),
            "name" => $_POST["name"]
        ));
        break;

    case "PUT":
        parse_str(file_get_contents("php://input"), $_PUT);

        $result = $authors->update(array(
            "id" => intval($_PUT["id"]),
            "name" => $_PUT["name"]
        ));
        break;

    case "DELETE":
        parse_str(file_get_contents("php://input"), $_DELETE);

        $result = $authors->remove(intval($_DELETE["id"]));
        break;
}

header("Content-Type: application/json");
echo json_encode($result);

?>