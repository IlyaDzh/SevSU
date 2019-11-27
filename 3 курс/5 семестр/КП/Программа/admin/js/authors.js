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
            { name: "id", title: "ID", type: "number", width: 60 },
            { name: "name", title: "ФИО", type: "text", width: 350, validate: "required" },
            { type: "control" }
        ]
    });

});