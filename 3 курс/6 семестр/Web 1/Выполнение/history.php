<?php

$title = "Ilya D. | История";
$header_scripts = array("history.js");
$active = "История";
require("header.php");

?>

    <section class="container content">
        <h4>История текущего сеанса</h4>
        <table class="table table-sm table-hover" id="localStorageTable">
            <thead class="thead-light">
                <tr>
                    <th scope="col">№</th>
                    <th scope="col">Страница</th>
                    <th scope="col">Посещений</th>
                </tr>
            </thead>
            <tbody>
                <script>getLocalStorageHistory();</script>
            </tbody>
        </table>
        <h4 class="mt-4">История за все время</h4>
        <table class="table table-sm table-hover" id="cookieTable">
            <thead class="thead-light">
                <tr>
                    <th scope="col">№</th>
                    <th scope="col">Страница</th>
                    <th scope="col">Посещений</th>
                </tr>
            </thead>
            <tbody>
                <script>getCookiesHistory();</script>
            </tbody>
        </table>
    </section>

<?php
    $footer_scripts = array(
        "jquery-3.4.1.min.js", 
        "time.js", 
        "dropdown.js"
    );
    require("footer.php");
?>