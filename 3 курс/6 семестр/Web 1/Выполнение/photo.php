<?php

$title = "Ilya D. | Фотоальбом";
$active = "Фотоальбом";
require("header.php");

?>

    <div class="popup_bg" id="img-bg"></div>

    <section class="content container">
        <div class="row">
            <script src="public/js/photo.js"></script>
        </div>
    </section>

    <div class="popup unselectable" id="popup-main">
        <img class="popup_img rounded" id="testimg" src="public/img/photo/ara-3601194_640.jpg" alt="">
    </div>

    <div class="control-block unselectable" id="control">
        <button class="control__btn" id="btn__left">&lt;</button>
        <span id="control__title">title</span>
        <button class="control__btn" id="btn__right">&gt;</button>
    </div>

<?php
    $footer_scripts = array(
        "jquery-3.4.1.min.js", 
        "history.js", 
        "time.js", 
        "openPhoto.js", 
        "dropdown.js"
    );
    require("footer.php");
?>