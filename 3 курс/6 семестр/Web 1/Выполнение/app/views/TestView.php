<section class="content container">
    <h2 class="mb-4">Тест по основам дискретной математики</h2>
    <form action="/test/check" method="POST">
        <div class="form-row mb-3">
            <div class="form-group col-md-6">
                <label for="inputFio">ФИО</label>
                <input type="text" class="form-control tooltip-input" name="ФИО" 
                    title="Фамилия Имя Отчество через пробел" placeholder="Введите ваше ФИО" autocomplete="off" autofocus>
            </div>
            <div class="form-group col-md-6">
                <label for="inputGroup">Группа</label>
                <input type="text" class="form-control tooltip-input" name="Группа" placeholder="Введите название группы"
                    title="Пример: ИС-32" autocomplete="off">
            </div>
        </div>
        <div class="form-group">
            <label for="checkQ">Операции над множествами:</label>
            <div id="checkQ">
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" id="inlineCheckbox1" name="checkbox1" value="option1">
                    <label class="form-check-label" for="inlineCheckbox1">Объединение</label>
                </div>
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" id="inlineCheckbox2" name="checkbox2" value="option2">
                    <label class="form-check-label" for="inlineCheckbox2">Импликация</label>
                </div>
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" id="inlineCheckbox3" name="checkbox3" value="option3">
                    <label class="form-check-label" for="inlineCheckbox3">Дополнение</label>
                </div>
            </div>
        </div>
        <div class="form-group">
            <label for="inputSelect">Количество собственных подмножеств множества из пяти элементов?</label>
            <select class="form-control" id="inputSelect" name="Вопрос_2">
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
        </div>
        <div class="form-group">
            <label for="inputQ">Что такое множество?</label>
            <input type="text" class="form-control" id="inputQ" name="Вопрос_3" placeholder="Введите ответ" autocomplete="off">
        </div>
        <button class="btn btn-primary" type="submit">Отправить</button>
        <button class="btn btn-danger" type="button">Очистить</button>
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