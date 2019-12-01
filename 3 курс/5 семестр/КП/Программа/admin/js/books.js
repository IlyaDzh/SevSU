$(function () {

    $("#jsGrid").jsGrid({
        height: "90%",
        width: "100%",
        filtering: true,
        inserting: true,
        editing: true,
        sorting: true,
        paging: true,
        autoload: true,
        pageSize: 9,
        pageButtonCount: 5,
        deleteConfirm: "Вы действительно хотите удалить книгу?",
        pagerFormat: "Страница: {first} {prev} {pages} {next} {last}    {pageIndex} из {pageCount}",
        pagePrevText: "Предыдущая",
        pageNextText: "Следующая",
        pageFirstText: "Первая",
        pageLastText: "Последняя",
        controller: {
            loadData: function (filter) {
                return $.ajax({
                    type: "GET",
                    url: "/pages/admin_books/",
                    data: filter
                });
            },
            insertItem: function (item) {
                return $.ajax({
                    type: "POST",
                    url: "/pages/admin_books/",
                    data: item
                });
            },
            updateItem: function (item) {
                return $.ajax({
                    type: "PUT",
                    url: "/pages/admin_books/",
                    data: item
                });
            },
            deleteItem: function (item) {
                return $.ajax({
                    type: "DELETE",
                    url: "/pages/admin_books/",
                    data: item
                });
            }
        },
        fields: [
            { name: "id", title: "ID", type: "number", width: 60 },
            { name: "name", title: "Название книги", type: "text", width: 160, validate: "required" },
            { name: "authors", title: "Авторы", type: "text", width: 140, validate: "required" },
            { name: "id_categories", title: "ID направления", type: "number", width: 160, validate: "required" },
            { name: "id_publish", title: "ID издательства", type: "number", width: 110, validate: "required" },
            {
                name: "date_create", title: "Дата издания", type: "text", width: 80,
                validate: function (value, item) {
                    return /^(19[0-9]{2}|2[0-9]{3})\-(0[1-9]|1[0-2])\-(0[1-9]|1[0-9]|2[0-9]|3[0-1])$/.test(value);
                }
            },
            { name: "number_pages", title: "Количество страниц", type: "number", width: 95, validate: "required" },
            { type: "control" }
        ]
    });

});