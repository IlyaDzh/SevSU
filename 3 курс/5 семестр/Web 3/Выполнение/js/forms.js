// 
//убрать это гавно
// 
function ValidTest() {
    if (checkFio() && checkGroup() && checkSelect() && checkAns()) {
        alert("Тест отправлен!");
        return true;
    }
    else return false;
}

function ValidContact() {
    if (checkFio() && checkDate() && checkNum() && checkEmail() && checkText()) {
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

function checkGroup() {
    var group = document.forms[0].inputGroup;
    if (group.value == '') {
        group.classList.add('is-invalid');
        group.focus();
        return false;
    }
    group.classList.remove('is-invalid');
    group.classList.add('is-valid');
    return true;
}

function checkEmail() {
    var email = document.forms[0].inputEmail;
    if (email.value == '') {
        email.classList.add('is-invalid');
        email.focus();
        return false;
    }
    email.classList.remove('is-invalid');
    email.classList.add('is-valid');
    return true;
}

function checkText() {
    var text = document.forms[0].inputText;
    if (text.value == '') {
        text.classList.add('is-invalid');
        text.focus();
        return false;
    }
    text.classList.remove('is-invalid');
    text.classList.add('is-valid');
    return true;
}

function checkDate() {
    var text = document.forms[0].inputDate;
    if (text.value == '') {
        text.classList.add('is-invalid');
        text.focus();
        return false;
    }
    text.classList.remove('is-invalid');
    text.classList.add('is-valid');
    return true;
}

// calendar

var calInput = document.getElementById("inputDate");
var calendar = document.getElementById("calendar");

calInput.addEventListener("click", () => {
    calendar.classList.add("visible");
    document.addEventListener('click', (event) => {
        if (event.target == calInput) return;
        var isClickInside = calendar.contains(event.target);
        if (!isClickInside)
            calendar.classList.remove("visible");
    });
});