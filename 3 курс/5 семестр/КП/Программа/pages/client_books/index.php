<?php

include "../../models/ClientBooksRepository.php";

$config = include("../../db/config.php");
$db = new PDO($config["db"], $config["username"], $config["password"]);
$books = new ClientBooksRepository($db);

switch($_SERVER["REQUEST_METHOD"]) {
    case "GET":
        $result = $books->getAll(array(
            "id" => intval($_GET["id"]),
            "name" => $_GET["name"],
            "authors" => $_GET["authors"],
            "categories" => $_GET["categories"],
            "publish" => $_GET["publish"],
            "date_create" => $_GET["date_create"],
            "number_pages" => intval($_GET["number_pages"])
        ));
        break;
}

header("Content-Type: application/json");
echo json_encode($result);

?>