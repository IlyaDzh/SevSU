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

var calDay = document.querySelectorAll(".calendar-content a");
var calMonth = document.getElementById("month");
var calYear = document.getElementById("years");
var selectDay, selectMonth, selectYear;

for (let i = 0; i < calDay.length; i++) {
    calDay[i].addEventListener("click", () => {
        var haveBg = document.getElementsByClassName("select-day-bg");
        if (haveBg.length != 0) {
            haveBg[0].childNodes[0].classList.remove("select-day");
            haveBg[0].classList.remove("select-day-bg");
        }
        selectDay = calDay[i].innerHTML;
        calDay[i].classList.add("select-day");
        calDay[i].parentElement.classList.add("select-day-bg");
    });
}

calMonth.addEventListener("change", () => {
    selectMonth = calMonth.value;
});

calYear.addEventListener("change", () => {
    selectYear = calYear.value;
});

var calButton = document.getElementById("calendarOk");

function btnClick() {
    calendar.classList.remove("visible");
    calInput.value = `${selectDay} ${selectMonth} ${selectYear}г.`;
    checkEmpty(document.forms[0].inputDate);
}