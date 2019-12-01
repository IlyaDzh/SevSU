$(function () {

    $("#jsGrid").jsGrid({
        height: "90%",
        width: "100%",
        filtering: true,
        sorting: true,
        paging: true,
        autoload: true,
        pageSize: 6,
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
                    url: "/pages/client_books/",
                    data: filter
                });
            }
        },
        fields: [
            { name: "id", title: "ID", type: "number", width: 40 },
            { name: "name", title: "Название книги", type: "text", width: 120, validate: "required" },
            { name: "authors", title: "Авторы", type: "text", width: 140, validate: "required" },
            { name: "categories", title: "Направление", type: "text", width: 120, validate: "required" },
            { name: "publish", title: "Издательство", type: "text", width: 80, validate: "required" },
            { name: "date_create", title: "Дата издания", type: "text", width: 70, validate: "required" },
            { name: "number_pages", title: "Количество страниц", type: "number", width: 85, validate: "required" },
            { type: "control", deleteButton: false, editButton: false }
        ]
    });

});