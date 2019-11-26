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
            { name: "id", title: "ID", type: "number", width: 30 },
            { name: "name", title: "Название книги", type: "text", width: 110, validate: "required" },
            { name: "authors", title: "Авторы", type: "text", width: 100, validate: "required" },
            { name: "categories", title: "Направление", type: "text", width: 130, validate: "required" },
            { name: "publish", title: "Издательство", type: "text", width: 60, validate: "required" },
            { name: "date_create", title: "Дата издания", type: "text", width: 40, validate: "required" },
            { name: "number_pages", title: "Количество страниц", type: "number", width: 60, validate: "required" },
            { type: "control" }
        ]
    });

});