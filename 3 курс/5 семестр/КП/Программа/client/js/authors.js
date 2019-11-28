$(function () {

    var degrees = [
        { degree: "", id: 0 },
        { degree: "нет", id: 1 },
        { degree: "кандидат наук", id: 2 },
        { degree: "доктор наук", id: 3 }
    ];

    $("#jsGrid").jsGrid({
        height: "90%",
        width: "100%",
        filtering: true,
        sorting: true,
        paging: true,
        autoload: true,
        pageSize: 15,
        pageButtonCount: 5,
        pagerFormat: "Страница: {first} {prev} {pages} {next} {last}    {pageIndex} из {pageCount}",
        pagePrevText: "Предыдущая",
        pageNextText: "Следующая",
        pageFirstText: "Первая",
        pageLastText: "Последняя",
        controller: {
            loadData: function (filter) {
                return $.ajax({
                    type: "GET",
                    url: "/pages/authors/",
                    data: filter
                });
            }
        },
        fields: [
            { name: "id", title: "ID", type: "number", width: 60 },
            { name: "name", title: "ФИО", type: "text", width: 350, validate: "required" },
            { name: "degree", title: "Учёная степень", type: "select", width: 100, items: degrees, valueField: "degree", textField: "degree", validate: "required" },
            { name: "date", title: "Дата рождения", type: "text", width: 80, validate: "required" },
            { type: "control", deleteButton: false, editButton: false }
        ]
    });

});