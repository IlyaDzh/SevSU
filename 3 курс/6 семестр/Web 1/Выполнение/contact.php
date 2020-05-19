<?php

$title = "Ilya D. | Контакт";
$active = "Контакт";
require("header.php");

?>

    <section class="content container">
        <form action="">
            <div class="form-group">
                <input type="text" class="form-control tooltip-input" id="inputFio"
                    title="Фамилия Имя Отчество через пробел" placeholder="Введите ваше ФИО" autocomplete="off"
                    autofocus oninput="checkFio()">
                <div class="invalid-feedback">
                    Неверный формат ввода! Пример: Иванов Иван Иванович
                </div>
            </div>
            <div class="form-group">
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="Radios" id="Radios1" value="option1" checked>
                    <label class="form-check-label" for="Radios1">Мужчина</label>
                </div>
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="Radios" id="Radios2" value="option2">
                    <label class="form-check-label" for="Radios2">Женщина</label>
                </div>
            </div>
            <div class="form-group">
                <input type="date" class="form-control tooltip-input" id="inputDate" 
                    title="Выберите вашу дату рождения" autocomplete="off"
                    oninput="checkEmpty(document.forms[0].inputDate)">
            </div>
            <div class="form-group">
                <input type="text" class="form-control tooltip-input" id="inputNum" title="Пример: +79781234567"
                    placeholder="Введите номер телефона" autocomplete="off" oninput="checkNum()">
                <div class="invalid-feedback">
                    Неверный формат ввода!
                </div>
            </div>
            <div class="form-group">
                <input type="text" class="form-control tooltip-input" id="inputEmail" title="Пример: ivanov@gmail.com"
                    placeholder="Введите email" autocomplete="off" oninput="checkMail()">
                <div class="invalid-feedback">
                    Неверный формат ввода! Пример: name@gmail.com
                </div>
            </div>
            <div class="form-group">
                <textarea class="form-control" id="inputText" rows="4" placeholder="Введите сообщение"
                    oninput="checkEmpty(document.forms[0].inputText)"></textarea>
                <div class="invalid-feedback">
                    Необходимо заполнить поле!
                </div>
            </div>
            <button class="btn btn-primary" type="submit" name="submit"
                onclick="return ValidContact()">Отправить</button>
            <button class="btn btn-danger" type="button">Очистить</button>
            <div class="modal">
                <div class="modal__content">
                    <p>Вы действительно хотите очистить форму?</p>
                    <form onsubmit="return false">
                        <button class="btn btn-outline-primary" type="reset" name="reset"
                            onclick="ClearContact()">Да</button>
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
        "history.js", 
        "time.js", 
        "forms.js", 
        "dropdown.js",
        "popover.js",
        "modal.js"
    );
    require("footer.php");
?>