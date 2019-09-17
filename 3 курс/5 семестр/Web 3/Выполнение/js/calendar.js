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