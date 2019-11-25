<?php

include "../../models/RentRepository.php";

$config = include("../../db/config.php");
$db = new PDO($config["db"], $config["username"], $config["password"]);
$rent = new RentRepository($db);

switch($_SERVER["REQUEST_METHOD"]) {
    case "GET":
        $result = $rent->getAll(array(
            "id" => intval($_GET["id"]),
            "name" => $_GET["name"],
            "category" => $_GET["category"],
            "publish" => $_GET["publish"],
            "date_create" => $_GET["date_create"],
            "number_pages" => intval($_GET["number_pages"])
        ));
        break;

    case "POST":
        $result = $rent->insert(array(
            "id" => intval($_POST["id"]),
            "name" => $_POST["name"],
            "category" => $_POST["category"],
            "publish" => $_POST["publish"],
            "date_create" => $_POST["date_create"],
            "number_pages" => intval($_POST["number_pages"])
        ));
        break;

    case "PUT":
        parse_str(file_get_contents("php://input"), $_PUT);

        $result = $rent->update(array(
            "id" => intval($_PUT["id"]),
            "name" => $_PUT["name"],
            "category" => $_PUT["category"],
            "publish" => $_PUT["publish"],
            "date_create" => $_PUT["date_create"],
            "number_pages" => intval($_PUT["number_pages"])
        ));
        break;

    case "DELETE":
        parse_str(file_get_contents("php://input"), $_DELETE);

        $result = $rent->remove(intval($_DELETE["id"]));
        break;
}

header("Content-Type: application/json");
echo json_encode($result);

?>