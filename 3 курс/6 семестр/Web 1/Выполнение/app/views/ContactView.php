<section class="content container">
    <form action="/contact/check" method="POST">
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" name="ФИО" 
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
            <input type="date" class="form-control tooltip-input" name="Дата" title="Выберите вашу дату рождения" autocomplete="off">
        </div>
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" name="Телефон" title="Пример: +79781234567"
                placeholder="Введите номер телефона" autocomplete="off">
        </div>
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" name="Email" title="Пример: ivanov@gmail.com"
                placeholder="Введите email" autocomplete="off">
        </div>
        <div class="form-group">
            <textarea class="form-control" name="message" rows="4" placeholder="Введите сообщение"></textarea>
        </div>
        <button class="btn btn-primary" type="submit">Отправить</button>
        <button class="btn btn-danger" type="button">Очистить</button>
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
        <div class="modal">
            <div class="modal__content">
                <p>Вы действительно хотите очистить форму?</p>
                <form onsubmit="return false">
                    <button class="btn btn-outline-primary" type="reset">Да</button>
                    <button class="btn btn-outline-primary" type="button">Нет</button>
                </form>
            </div>
        </div>
    </form>
</section>

<div class="cover"></div>

<script src="/public/js/modal.js"></script>