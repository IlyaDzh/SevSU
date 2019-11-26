<?php

include "../../models/RentRepository.php";

$config = include("../../db/config.php");
$db = new PDO($config["db"], $config["username"], $config["password"]);
$rent = new RentRepository($db);

switch($_SERVER["REQUEST_METHOD"]) {
    case "GET":
        $result = $rent->getAll(array(
            "id" => intval($_GET["id"]),
            "books" => $_GET["books"],
            "readers" => $_GET["readers"],
            "date_rent" => $_GET["date_rent"],
            "date_return" => $_GET["date_return"]
        ));
        break;

    case "POST":
        $result = $rent->insert(array(
            "id" => intval($_POST["id"]),
            "books" => $_POST["books"],
            "readers" => $_POST["readers"],
            "date_rent" => $_POST["date_rent"],
            "date_return" => $_POST["date_return"]
        ));
        break;

    case "PUT":
        parse_str(file_get_contents("php://input"), $_PUT);

        $result = $rent->update(array(
            "id" => intval($_PUT["id"]),
            "books" => $_PUT["books"],
            "readers" => $_PUT["readers"],
            "date_rent" => $_PUT["date_rent"],
            "date_return" => $_PUT["date_return"]
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