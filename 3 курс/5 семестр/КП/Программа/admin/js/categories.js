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
        pageSize: 15,
        pageButtonCount: 5,
        deleteConfirm: "Вы действительно хотите удалить направление?",
        pagerFormat: "Страница: {first} {prev} {pages} {next} {last}    {pageIndex} из {pageCount}",
        pagePrevText: "Предыдущая",
        pageNextText: "Следующая",
        pageFirstText: "Первая",
        pageLastText: "Последняя",
        controller: {
            loadData: function (filter) {
                return $.ajax({
                    type: "GET",
                    url: "/pages/categories/",
                    data: filter
                });
            },
            insertItem: function (item) {
                return $.ajax({
                    type: "POST",
                    url: "/pages/categories/",
                    data: item
                });
            },
            updateItem: function (item) {
                return $.ajax({
                    type: "PUT",
                    url: "/pages/categories/",
                    data: item
                });
            },
            deleteItem: function (item) {
                return $.ajax({
                    type: "DELETE",
                    url: "/pages/categories/",
                    data: item
                });
            }
        },
        fields: [
            { name: "id", title: "ID", type: "number", width: 60, editing: false },
            { name: "description", title: "Описание", type: "text", width: 350, validate: "required" },
            { type: "control" }
        ]
    });

});