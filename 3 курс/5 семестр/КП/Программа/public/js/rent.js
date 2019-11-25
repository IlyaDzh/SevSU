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
            { name: "id", title: "ID", type: "number", width: 20 },
            { name: "books", title: "Книга", type: "text", width: 115, validate: "required" },
            { name: "readers", title: "Читатели", type: "text", width: 115, validate: "required" },
            { name: "date_rent", title: "Дата выдачи", type: "text", width: 115, validate: "required" },
            { name: "date_return", title: "Дата возврата", type: "text", width: 55, validate: "required" },
            { type: "control" }
        ]
    });

});