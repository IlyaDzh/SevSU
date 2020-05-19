<?php

$title = "Ilya D. | Главная";
$active = "Главная";
require("header.php");

?>

    <section class="main-content container">
        <div class="lab-work mt-5">
            <h4 class="lab__number">Лабораторная работа №8:</h4>
            <h5 class="lab__name">
                "Исследование архитектуры MVC приложения и возможностей обработки 
                <br>
                данных HTML-форм на стороне сервера с использованием языка PHP"
            </h5>
        </div>
        <div class="main-image">
            <img src="public/img/photo-main.jpg" class="main__photo" alt="My photo">
        </div>
        <h1 class="main__fio">Долженко Илья Андреевич</h1>
        <h2 class="main__group">ИС-32-о</h2>
    </section>

<?php
    $footer_scripts = array(
        "jquery-3.4.1.min.js", 
        "history.js", 
        "time.js", 
        "dropdown.js"
    );
    require("footer.php");
?>