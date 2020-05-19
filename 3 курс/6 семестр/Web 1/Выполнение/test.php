<?php

$title = "Ilya D. | Тест";
$active = "Тест";
require("header.php");

?>

    <section class="content container">
        <h2 class="mb-4">Тест по основам дискретной математики</h2>
        <form action="">
            <div class="form-row mb-3">
                <div class="form-group col-md-6">
                    <label for="inputFio">ФИО</label>
                    <input type="text" class="form-control tooltip-input" id="inputFio"
                        title="Фамилия Имя Отчество через пробел" placeholder="Введите ваше ФИО" autocomplete="off"
                        autofocus oninput="checkFio()">
                    <div class="invalid-feedback">
                        Неверный формат ввода! Пример: Иванов Иван Иванович
                    </div>
                </div>
                <div class="form-group col-md-6">
                    <label for="inputGroup">Группа</label>
                    <input type="text" class="form-control tooltip-input" id="inputGroup" placeholder="Введите название группы"
                        title="Пример: ИС-32" autocomplete="off"
                        oninput="checkEmpty(document.forms[0].inputGroup)">
                    <div class="invalid-feedback">
                        Необходимо заполнить поле!
                    </div>
                </div>
            </div>
            <div class="form-group">
                <label for="checkQ">Операции над множествами:</label>
                <div id="checkQ">
                    <div class="form-check">
                        <input class="form-check-input" type="checkbox" id="inlineCheckbox1" value="option1">
                        <label class="form-check-label" for="inlineCheckbox1">Объединение</label>
                    </div>
                    <div class="form-check">
                        <input class="form-check-input" type="checkbox" id="inlineCheckbox2" value="option2">
                        <label class="form-check-label" for="inlineCheckbox2">Импликация</label>
                    </div>
                    <div class="form-check">
                        <input class="form-check-input" type="checkbox" id="inlineCheckbox3" value="option3">
                        <label class="form-check-label" for="inlineCheckbox3">Дополнение</label>
                    </div>
                </div>
            </div>
            <div class="form-group">
                <label for="inputSelect">Количество собственных подмножеств множества из пяти элементов?</label>
                <select class="form-control" id="inputSelect" oninput="checkSelect()">
                    <option>Выберите ответ</option>
                    <optgroup label=">30">
                        <option>31</option>
                        <option>32</option>
                        <option>33</option>
                    </optgroup>
                    <optgroup label="<30">
                        <option>2</option>
                        <option>20</option>
                        <option>25</option>
                        <option>28</option>
                    </optgroup>
                </select>
                <div class="invalid-feedback">
                    Необходимо заполнить поле!
                </div>
            </div>
            <div class="form-group">
                <label for="inputQ">Что такое множество?</label>
                <input type="text" class="form-control" id="inputQ" placeholder="Введите ответ" autocomplete="off"
                    oninput="checkAns()">
                <div class="invalid-feedback">
                    Пустое поле или ответ содержит цифры!
                </div>
            </div>
            <button class="btn btn-primary" type="submit" name="submit" onclick="return ValidTest()">Отправить</button>
            <button class="btn btn-danger" type="button">Очистить</button>
            <div class="modal">
                <div class="modal__content">
                    <p>Вы действительно хотите очистить форму?</p>
                    <form onsubmit="return false">
                        <button class="btn btn-outline-primary" type="reset" name="reset" onclick="ClearTest()">Да</button>
                        <button class="btn btn-outline-primary" type="button">Нет</button>
                    </form>
                </div>
            </div>
        </form>
    </section>

    <div class="cover"></div>

<?php
    $footer_scripts = array(
        "jquery-3.4.1.min.js", 
        "popover.js",
        "history.js", 
        "time.js", 
        "forms.js", 
        "dropdown.js",
        "modal.js"
    );
    require("footer.php");
?>