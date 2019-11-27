$(function () {

    $("#jsGrid").jsGrid({
        height: "70%",
        width: "100%",
        filtering: true,
        inserting: true,
        editing: true,
        sorting: true,
        paging: true,
        autoload: true,
        pageSize: 9,
        pageButtonCount: 5,
        deleteConfirm: "Вы действительно хотите удалить запись о выдаче?",
        pagerFormat: "Страница: {first} {prev} {pages} {next} {last}    {pageIndex} из {pageCount}",
        pagePrevText: "Предыдущая",
        pageNextText: "Следующая",
        pageFirstText: "Первая",
        pageLastText: "Последняя",
        controller: {
            loadData: function (filter) {
                return $.ajax({
                    type: "GET",
                    url: "/pages/rent/",
                    data: filter
                });
            },
            insertItem: function (item) {
                return $.ajax({
                    type: "POST",
                    url: "/pages/rent/",
                    data: item
                });
            },
            updateItem: function (item) {
                return $.ajax({
                    type: "PUT",
                    url: "/pages/rent/",
                    data: item
                });
            },
            deleteItem: function (item) {
                return $.ajax({
                    type: "DELETE",
                    url: "/pages/rent/",
                    data: item
                });
            }
        },
        fields: [
            { name: "id", title: "ID", type: "number", width: 60 },
            { name: "books", title: "Книга", type: "text", width: 150, validate: "required" },
            { name: "readers", title: "Читатель", type: "text", width: 150, validate: "required" },
            {
                name: "date_rent", title: "Дата выдачи", type: "text", width: 80,
                validate: function (value, item) {
                    return /^(19[0-9]{2}|2[0-9]{3})\-(0[1-9]|1[0-2])\-(0[1-9]|1[0-9]|2[0-9]|3[0-1])$/.test(value);
                }
            },
            {
                name: "date_return", title: "Дата возврата", type: "text", width: 80,
                validate: function (value, item) {
                    return /^(19[0-9]{2}|2[0-9]{3})\-(0[1-9]|1[0-2])\-(0[1-9]|1[0-9]|2[0-9]|3[0-1])$/.test(value);
                }
            },
            { type: "control" }
        ]
    });

});