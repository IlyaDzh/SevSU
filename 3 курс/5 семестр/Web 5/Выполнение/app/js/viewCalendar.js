function viewCalendar() {
    var date = new Date();
    var nowDate = daysInMonth(date.getMonth() + 1, date.getFullYear());

    document.writeln("<tr>");
    for (var i = 1; i < nowDate + 1; i++) {
        document.writeln(`<td><a href="#">${i}</a></td>`);
        if (i % 7 == 0) {
            document.writeln("</tr><tr>");
        }
    }
    document.writeln("</tr>");
    upateVariable();
}

function daysInMonth(month, year) {
    return new Date(year, month, 0).getDate();
}

function updateCalendar() {
    var tbody = document.getElementById("tbodyCalendar");
    var years = document.getElementById("years");
    var month = document.getElementById("month");

    var yearsValue = years.options[years.selectedIndex].text;
    var monthValue = month.selectedIndex;

    var date = new Date(yearsValue, monthValue);
    var nowDate = daysInMonth(date.getMonth(), date.getFullYear());

    var tr = document.createElement("tr");
    tbody.innerHTML = "";

    for (var i = 1; i < nowDate + 1; i++) {
        var td = document.createElement("td");
        var a = document.createElement("a");
        a.setAttribute("href", "#");
        var textnode = document.createTextNode(i);
        a.appendChild(textnode);
        td.appendChild(a);
        tr.appendChild(td);
        if (i % 7 == 0) {
            tbody.appendChild(tr);
            tr = document.createElement("tr");
        }
        if (i == nowDate)
            tbody.appendChild(tr);
    }
    upateVariable();
}