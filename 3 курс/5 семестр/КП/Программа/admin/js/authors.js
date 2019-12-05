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
        inserting: true,
        editing: true,
        sorting: true,
        paging: true,
        autoload: true,
        pageSize: 15,
        pageButtonCount: 5,
        deleteConfirm: "Вы действительно хотите удалить автора?",
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
            },
            insertItem: function (item) {
                return $.ajax({
                    type: "POST",
                    url: "/pages/authors/",
                    data: item
                });
            },
            updateItem: function (item) {
                return $.ajax({
                    type: "PUT",
                    url: "/pages/authors/",
                    data: item
                });
            },
            deleteItem: function (item) {
                return $.ajax({
                    type: "DELETE",
                    url: "/pages/authors/",
                    data: item
                });
            }
        },
        fields: [
            { name: "id", title: "ID", type: "number", width: 60, editing: false },
            { name: "name", title: "ФИО", type: "text", width: 350, validate: "required" },
            { name: "degree", title: "Учёная степень", type: "select", width: 100, items: degrees, valueField: "degree", textField: "degree", validate: "required" },
            {
                name: "date", title: "Дата рождения", type: "text", width: 80,
                validate: function (value, item) {
                    return /^(19[0-9]{2}|2[0-9]{3})\-(0[1-9]|1[0-2])\-(0[1-9]|1[0-9]|2[0-9]|3[0-1])$/.test(value);
                }
            },
            { type: "control" }
        ]
    });

});