<?php     $title = 'Ilya D. | Тест';    include 'header.php'?><section class="content container"><h2 class="mb-4">Тест по основам дискретной математики</h2><form><div class="form-row mb-3"><div class="form-group col-md-6"><label for="inputFio">ФИО</label><input autocomplete="off" autofocus="true" oninput="checkFio()" placeholder="Введите ваше ФИО" title="Фамилия Имя Отчество через пробел" type="text" class="form-control tooltip-input" id="inputFio" /><div class="invalid-feedback">Неверный формат ввода! Пример: Иванов Иван Иванович</div></div><div class="form-group col-md-6"><label for="inputGroup">Группа</label><input autocomplete="off" oninput="checkEmpty(document.forms[0].inputGroup)" placeholder="Введите название группы" title="Пример: ИС-32" type="text" class="form-control tooltip-input" id="inputGroup" /><div class="invalid-feedback">Необходимо заполнить поле!</div></div></div><div class="form-group"><label for="checkQ">Операции над множествами:</label><div id="checkQ"><div class="form-check"><input type="checkbox" value="option1" class="form-check-input" id="inlineCheckbox1" /><label for="inlineCheckbox1" class="form-check-label">Объединение</label></div><div class="form-check"><input type="checkbox" value="option2" class="form-check-input" id="inlineCheckbox2" /><label for="inlineCheckbox2" class="form-check-label">Импликация</label></div><div class="form-check"><input type="checkbox" value="option3" class="form-check-input" id="inlineCheckbox3" /><label for="inlineCheckbox3" class="form-check-label">Дополнение</label></div></div></div><div class="form-group"><label for="inputSelect">Количество собственных подмножеств множества из пяти элементов?</label><select oninput="checkSelect()" class="form-control" id="inputSelect"><option>Выберите ответ</option><optgroup label="&gt;30"></optgroup><option>31</option><option>32</option><option>33</option><optgroup label="&lt;30"></optgroup><option>2</option><option>20</option><option>25</option><option>28</option></select></div><div class="invalid-feedback">Необходимо заполнить поле!</div><div class="form-group"><label for="inputQ">Что такое множество?</label><input autocomplete="off" oninput="checkAns()" placeholder="Введите ответ" type="text" class="form-control" id="inputQ" /><div class="invalid-feedback">Пустое поле или ответ содержит цифры!</div></div><button name="submit" onclick="return ValidTest()" type="submit" class="btn btn-primary mr-1">Отправить</button><button type="button" class="btn btn-danger">Очистить</button><div class="modal"><div class="modal__content"><p>Вы действительно хотите очистить форму?</p><form onsubmit="return false"><button name="reset" onclick="ClearTest()" type="reset" class="btn btn-outline-primary mr-1">Да</button><button type="button" class="btn btn-outline-primary">Нет</button></form></div></div></form></section><div class="cover"></div><script src="js/jquery-3.4.1.min.js"></script><script src="js/history.js"></script><script src="js/time.js"></script><script src="js/dropdown.js"></script><script src="js/forms.js"></script><script src="js/popover.js"></script><script src="js/modal.js"></script>