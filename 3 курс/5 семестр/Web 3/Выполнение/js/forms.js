function ValidTest() {
    if (checkFio() && checkEmpty(document.forms[0].inputGroup) && checkSelect() && checkAns()) {
        alert("Тест отправлен!");
        return true;
    }
    else return false;
}

function ValidContact() {
    if (checkFio() && checkEmpty(document.forms[0].inputDate) && checkNum() && checkEmpty(document.forms[0].inputEmail) && checkEmpty(document.forms[0].inputText)) {
        alert("Форма отправлена!");
        return true;
    }
    else return false;
}

function checkAns() {
    var ans = document.forms[0].inputQ;
    if (ans.value.match(/[0-9]+/) || ans.value == '') {
        ans.classList.add('is-invalid');
        ans.focus();
        return false;
    }
    ans.classList.remove('is-invalid');
    ans.classList.add('is-valid');
    return true;
}

function checkFio() {
    var fio = document.forms[0].inputFio;
    var fioLength = fio.value.trim().split(/\s+/).length;
    if ((fioLength != 3) || (fio.value.match(/[0-9]+/))) {
        fio.classList.add('is-invalid');
        fio.focus();
        return false;
    }
    fio.classList.remove('is-invalid');
    fio.classList.add('is-valid');
    return true;
}

function checkNum() {
    var number = document.forms[0].inputNum;
    if (!number.value.match(/^\+(7|3)\d{8,10}$/)) {
        number.classList.add('is-invalid');
        number.focus();
        return false;
    }
    number.classList.remove('is-invalid');
    number.classList.add('is-valid');
    return true;
}

function checkSelect(select) {
    var select = document.forms[0].inputSelect;
    if (select.selectedIndex == 0) {
        select.classList.add('is-invalid');
        select.focus();
        return false;
    }
    select.classList.remove('is-invalid');
    select.classList.add('is-valid');
    return true;
}

function checkEmpty(input) {
    if (input.value == '') {
        input.classList.add('is-invalid');
        input.focus();
        return false;
    }
    input.classList.remove('is-invalid');
    input.classList.add('is-valid');
    return true;
}