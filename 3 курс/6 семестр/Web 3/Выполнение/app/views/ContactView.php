<section class="content container">
    <form action="/contact/check" method="POST">
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" name="fullname" value="<?if (isset($_POST["fullname"])) echo $_POST["fullname"];?>"
                title="Фамилия Имя Отчество через пробел" placeholder="Введите ваше ФИО" autocomplete="off">
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
            <input type="date" class="form-control tooltip-input" name="date" title="Выберите вашу дату рождения" 
                autocomplete="off" value="<?if (isset($_POST["date"])) echo $_POST["date"];?>">
        </div>
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" name="phone" title="Пример: +79781234567"
                placeholder="Введите номер телефона" value="<?if (isset($_POST["phone"])) echo $_POST["phone"];?>" 
                autocomplete="off">
        </div>
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" name="Email" title="Пример: ivanov@gmail.com"
                value="<?if (isset($_POST["Email"])) echo $_POST["Email"];?>" 
                placeholder="Введите email" autocomplete="off">
        </div>
        <div class="form-group">
            <textarea class="form-control" name="message" rows="4" placeholder="Введите сообщение"><?if (isset($_POST["message"])) echo $_POST["message"];?></textarea>
        </div>
        <button class="btn btn-primary" type="submit">Отправить</button>
    </form>
    <div class='result-block'>
        <?php 
            if (isset($data['errors'])) {
                if (count($data['errors']) > 0) {
                    foreach ($data['errors'] as $key => $item) {
                        echo "<p class='result-block__item error'>$item</p>";
                    }
                } else {
                    echo "<p class='result-block__item success'>Форма была отправлена</p>";
                }
            }
        ?>
    </div>
</section>