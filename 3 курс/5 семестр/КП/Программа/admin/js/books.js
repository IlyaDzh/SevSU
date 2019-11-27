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
                    url: "/pages/books/",
                    data: filter
                });
            },
            insertItem: function (item) {
                return $.ajax({
                    type: "POST",
                    url: "/pages/books/",
                    data: item
                });
            },
            updateItem: function (item) {
                return $.ajax({
                    type: "PUT",
                    url: "/pages/books/",
                    data: item
                });
            },
            deleteItem: function (item) {
                return $.ajax({
                    type: "DELETE",
                    url: "/pages/books/",
                    data: item
                });
            }
        },
        fields: [
            { name: "id", title: "ID", type: "number", width: 60 },
            { name: "name", title: "Название книги", type: "text", width: 120, validate: "required" },
            { name: "authors", title: "Авторы", type: "text", width: 150, validate: "required" },
            { name: "categories", title: "Направление", type: "text", width: 180, validate: "required" },
            { name: "publish", title: "Издательство", type: "text", width: 110, validate: "required" },
            { name: "date_create", title: "Дата издания", type: "text", width: 80, validate: "required" },
            { name: "number_pages", title: "Количество страниц", type: "number", width: 95, validate: "required" },
            { type: "control" }
        ]
    });

});