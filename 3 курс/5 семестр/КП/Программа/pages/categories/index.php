<?php

include "../../models/CategoriesRepository.php";

$config = include("../../db/config.php");
$db = new PDO($config["db"], $config["username"], $config["password"]);
$categories = new CategoriesRepository($db);

switch($_SERVER["REQUEST_METHOD"]) {
    case "GET":
        $result = $categories->getAll(array(
            "id" => intval($_GET["id"]),
            "description" => $_GET["description"]
        ));
        break;

    case "POST":
        $result = $categories->insert(array(
            "id" => intval($_POST["id"]),
            "description" => $_POST["description"]
        ));
        break;

    case "PUT":
        parse_str(file_get_contents("php://input"), $_PUT);

        $result = $categories->update(array(
            "id" => intval($_PUT["id"]),
            "description" => $_PUT["description"]
        ));
        break;

    case "DELETE":
        parse_str(file_get_contents("php://input"), $_DELETE);

        $result = $categories->remove(intval($_DELETE["id"]));
        break;
}

header("Content-Type: application/json");
echo json_encode($result);

?>