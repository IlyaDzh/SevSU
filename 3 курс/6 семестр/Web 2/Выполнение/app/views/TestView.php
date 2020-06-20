<section class="content container">
    <h2 class="mb-4">Тест по основам дискретной математики</h2>
    <form action="/test/check" method="POST">
        <div class="form-row mb-3">
            <div class="form-group col-md-6">
                <label for="inputFio">ФИО</label>
                <input type="text" class="form-control tooltip-input" name="fullname" 
                    title="Фамилия Имя Отчество через пробел" placeholder="Введите ваше ФИО" 
                    value="<?if (isset($_POST["fullname"])) echo $_POST["fullname"];?>" autocomplete="off" autofocus>
            </div>
            <div class="form-group col-md-6">
                <label for="inputGroup">Группа</label>
                <input type="text" class="form-control tooltip-input" name="group" placeholder="Введите название группы"
                    value="<?if (isset($_POST["group"])) echo $_POST["group"];?>" title="Пример: ИС-32" autocomplete="off">
            </div>
        </div>
        <div class="form-group">
            <label for="checkQ">Операции над множествами:</label>
            <div id="checkQ">
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" id="inlineCheckbox1" 
                        <? echo isset($_POST["checkbox1"]) ? "checked" : "" ?>
                        name="checkbox1" value="Объединение">
                    <label class="form-check-label" for="inlineCheckbox1">Объединение</label>
                </div>
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" id="inlineCheckbox2" 
                        <? echo isset($_POST["checkbox2"]) ? "checked" : "" ?>
                        name="checkbox2" value="Импликация">
                    <label class="form-check-label" for="inlineCheckbox2">Импликация</label>
                </div>
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" id="inlineCheckbox3" 
                        <? echo isset($_POST["checkbox3"]) ? "checked" : "" ?>
                        name="checkbox3" value="Дополнение">
                    <label class="form-check-label" for="inlineCheckbox3">Дополнение</label>
                </div>
            </div>
        </div>
        <div class="form-group">
            <label for="inputSelect">Количество собственных подмножеств множества из пяти элементов?</label>
            <select class="form-control" id="inputSelect" name="q2">
                <option>Выберите ответ</option>
                <optgroup label=">30">
                    <option <?= $_POST["q2"] === "31" ? " selected='selected'" : "" ?>>31</option>
                    <option <?= $_POST["q2"] === "32" ? " selected='selected'" : "" ?>>32</option>
                    <option <?= $_POST["q2"] === "33" ? " selected='selected'" : "" ?>>33</option>
                </optgroup>
                <optgroup label="<30">
                    <option <?= $_POST["q2"] === "2" ? " selected='selected'" : "" ?>>2</option>
                    <option <?= $_POST["q2"] === "20" ? " selected='selected'" : "" ?>>20</option>
                    <option <?= $_POST["q2"] === "25" ? " selected='selected'" : "" ?>>25</option>
                    <option <?= $_POST["q2"] === "28" ? " selected='selected'" : "" ?>>28</option>
                </optgroup>
            </select>
        </div>
        <div class="form-group">
            <label for="inputQ">Что такое множество?</label>
            <input type="text" class="form-control" id="inputQ" name="q3" 
                value="<?if (isset($_POST["q3"])) echo $_POST["q3"];?>" placeholder="Введите ответ" autocomplete="off">
        </div>
        <button class="btn btn-primary" type="submit">Отправить</button>
    </form>
    <div class='result-block'>
        <?php 
            if (isset($data['errors'])) {
                foreach ($data['errors'] as $key => $item) {
                    echo "<p class='result-block__item error'>$item</p>";
                }
            } elseif (isset($data['result'])) {
                $result = $data['result'];
                $color = $data['result'] > 2 ? 'success' : 'error';
                echo "<p class='result-block__item $color'>Вы ответили верно на $result из 3 вопросов!</p>";
            }
        ?>
    </div>
</section>