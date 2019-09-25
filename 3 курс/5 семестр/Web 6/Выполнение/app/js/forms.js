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

function checkAns() {
    var ans = document.forms[0].inputQ;
    if (ans.value.match(/[0-9]+/) || ans.value == '') {
        $(ans).addClass("is-invalid");
        ans.focus();
        return false;
    }
    $(ans).removeClass("is-invalid");
    $(ans).addClass("is-valid");
    return true;
}

function checkFio() {
    var fio = document.forms[0].inputFio;
    var fioLength = fio.value.trim().split(/\s+/).length;
    if ((fioLength != 3) || (fio.value.match(/[0-9]+/))) {
        $(fio).addClass("is-invalid");
        fio.focus();
        return false;
    }
    $(fio).removeClass("is-invalid");
    $(fio).addClass("is-valid");
    return true;
}

function checkNum() {
    var number = document.forms[0].inputNum;
    if (!number.value.match(/^\+(7|3)\d{8,10}$/)) {
        $(number).addClass("is-invalid");
        number.focus();
        return false;
    }
    $(number).removeClass("is-invalid");
    $(number).addClass("is-valid");
    return true;
}

function checkSelect(select) {
    var select = document.forms[0].inputSelect;
    if (select.selectedIndex == 0) {
        $(select).addClass("is-invalid");
        select.focus();
        return false;
    }
    $(select).removeClass("is-invalid");
    $(select).addClass("is-valid");
    return true;
}

function checkEmpty(input) {
    if (input.value == '') {
        $(input).addClass("is-invalid");
        input.focus();
        return false;
    }
    $(input).removeClass("is-invalid");
    $(input).addClass("is-valid");
    return true;
}