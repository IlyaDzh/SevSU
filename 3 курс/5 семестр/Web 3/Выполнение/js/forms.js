function ClearTest() {
    var ans = document.forms[0].inputQ;
    var fio = document.forms[0].inputFio;
    var group = document.forms[0].inputGroup;
    var select = document.forms[0].inputSelect;

    ans.classList.remove('is-invalid');
    fio.classList.remove('is-invalid');
    group.classList.remove('is-invalid');
    select.classList.remove('is-invalid');
    ans.classList.remove('is-valid');
    fio.classList.remove('is-valid');
    group.classList.remove('is-valid');
    select.classList.remove('is-valid');
}

function ClearContact() {
    var fio = document.forms[0].inputFio;
    var number = document.forms[0].inputNum;
    var date = document.forms[0].inputDate;
    var email = document.forms[0].inputEmail;
    var text = document.forms[0].inputText;

    number.classList.remove('is-invalid');
    fio.classList.remove('is-invalid');
    email.classList.remove('is-invalid');
    date.classList.remove('is-invalid');
    text.classList.remove('is-invalid');
    number.classList.remove('is-valid');
    fio.classList.remove('is-valid');
    email.classList.remove('is-valid');
    date.classList.remove('is-valid');
    text.classList.remove('is-valid');
}

function ValidTest() {
    if (checkFio() && checkEmpty(document.forms[0].inputGroup) && checkSelect() && checkAns()) {
        // alert("Тест отправлен!");
        return true;
    }
    else return false;
}

function ValidContact() {
    if (checkFio() && checkEmpty(document.forms[0].inputDate) && checkNum() && checkMail() && checkEmpty(document.forms[0].inputText)) {
        // alert("Форма отправлена!");
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

function checkMail() {
    var email = document.forms[0].inputEmail;
    if (!email.value.match(/[0-9a-z_]+@[0-9a-z_]+\.[a-z]{2,5}/i) || email.value == '') {
        email.classList.add('is-invalid');
        email.focus();
        return false;
    }
    email.classList.remove('is-invalid');
    email.classList.add('is-valid');
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