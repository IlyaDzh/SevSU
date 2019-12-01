<?php

include "../../models/AdminBooksRepository.php";

$config = include("../../db/config.php");
$db = new PDO($config["db"], $config["username"], $config["password"]);
$books = new AdminBooksRepository($db);

switch($_SERVER["REQUEST_METHOD"]) {
    case "GET":
        $result = $books->getAll(array(
            "id" => intval($_GET["id"]),
            "name" => $_GET["name"],
            "id_categories" => intval($_GET["id_categories"]),
            "id_publish" => intval($_GET["id_publish"]),
            "date_create" => $_GET["date_create"],
            "number_pages" => intval($_GET["number_pages"])
        ));
        break;

    case "POST":
        $result = $books->insert(array(
            "id" => intval($_POST["id"]),
            "name" => $_POST["name"],
            "id_categories" => intval($_POST["id_categories"]),
            "id_publish" => intval($_POST["id_publish"]),
            "date_create" => $_POST["date_create"],
            "number_pages" => intval($_POST["number_pages"])
        ));
        break;

    case "PUT":
        parse_str(file_get_contents("php://input"), $_PUT);

        $result = $books->update(array(
            "id" => intval($_PUT["id"]),
            "name" => $_PUT["name"],
            "id_categories" => intval($_PUT["id_categories"]),
            "id_publish" => intval($_PUT["id_publish"]),
            "date_create" => $_PUT["date_create"],
            "number_pages" => intval($_PUT["number_pages"])
        ));
        break;

    case "DELETE":
        parse_str(file_get_contents("php://input"), $_DELETE);

        $result = $books->remove(intval($_DELETE["id"]));
        break;
}

header("Content-Type: application/json");
echo json_encode($result);

?>