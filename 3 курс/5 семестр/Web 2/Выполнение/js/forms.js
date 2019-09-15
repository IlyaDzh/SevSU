function ValidTest() {
    var ans = document.forms[0].inputQ;
    var fio = document.forms[0].inputFIO;
    var group = document.forms[0].inputGroup;
    var select = document.forms[0].selectQ;

    if (checkFio(fio) && checkOther(group) && checkSelect(select) && checkAns(ans)) {
        alert("Тест отправлен!");
        return true;
    }
    else return false;
}

function checkAns(ans) {
    if (ans.value.match(/[0-9]+/) || ans.value == '') {
        ans.classList.add('is-invalid');
        ans.focus();
        return false;
    }
    ans.classList.remove('is-invalid');
    return true;
}

function ValidContact() {
    var fio = document.forms[0].inputFio;
    var number = document.forms[0].inputNum;
    var select = document.forms[0].inputSelect;
    var email = document.forms[0].inputEmail;
    var text = document.forms[0].inputText;

    if (checkFio(fio) && checkSelect(select) && checkNum(number) && checkOther(email) && checkOther(text)) {
        alert("Форма отправлена!");
        return true;
    }
    else return false;
}

function checkFio(fio) {
    var arrayFio = fio.value.split(' ');
    if ((arrayFio.length != 3) || (fio.value.match(/[0-9]+/))) {
        fio.classList.add('is-invalid');
        fio.focus();
        return false;
    }
    fio.classList.remove('is-invalid');
    return true;
}

function checkNum(number) {
    if (!number.value.match(/^\+(7|3)\d{8,10}$/)) {
        number.classList.add('is-invalid');
        number.focus();
        return false;
    }
    number.classList.remove('is-invalid');
    return true;
}

function checkSelect(select) {
    if (select.selectedIndex == 0) {
        select.classList.add('is-invalid');
        select.focus();
        return false;
    }
    select.classList.remove('is-invalid');
    return true;
}

function checkOther(other) {
    if (other.value == '') {
        other.classList.add('is-invalid');
        other.focus();
        return false;
    }
    other.classList.remove('is-invalid');
    return true;
}