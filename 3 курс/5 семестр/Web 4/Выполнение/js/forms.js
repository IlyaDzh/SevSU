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