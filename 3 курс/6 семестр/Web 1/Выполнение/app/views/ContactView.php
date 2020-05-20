<section class="content container">
    <form action="">
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" id="inputFio"
                title="Фамилия Имя Отчество через пробел" placeholder="Введите ваше ФИО" autocomplete="off">
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
            <input type="date" class="form-control tooltip-input" id="inputDate" title="Выберите вашу дату рождения" 
                autocomplete="off">
        </div>
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" id="inputNum" title="Пример: +79781234567"
                placeholder="Введите номер телефона" autocomplete="off">
            <div class="invalid-feedback">
                Неверный формат ввода!
            </div>
        </div>
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" id="inputEmail" title="Пример: ivanov@gmail.com"
                placeholder="Введите email" autocomplete="off">
            <div class="invalid-feedback">
                Неверный формат ввода! Пример: name@gmail.com
            </div>
        </div>
        <div class="form-group">
            <textarea class="form-control" id="inputText" rows="4" placeholder="Введите сообщение"></textarea>
            <div class="invalid-feedback">
                Необходимо заполнить поле!
            </div>
        </div>
        <button class="btn btn-primary" type="submit" name="submit">Отправить</button>
        <button class="btn btn-danger" type="button">Очистить</button>
        <div class="modal">
            <div class="modal__content">
                <p>Вы действительно хотите очистить форму?</p>
                <form onsubmit="return false">
                    <button class="btn btn-outline-primary" type="reset" name="reset">Да</button>
                    <button class="btn btn-outline-primary" type="button">Нет</button>
                </form>
            </div>
        </div>
    </form>
</section>

<div class="cover"></div>

<script src="public/js/modal.js"></script>