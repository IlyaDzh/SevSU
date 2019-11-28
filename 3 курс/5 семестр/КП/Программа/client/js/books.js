$(function () {

    $("#jsGrid").jsGrid({
        height: "90%",
        width: "100%",
        filtering: true,
        sorting: true,
        paging: true,
        autoload: true,
        pageSize: 7,
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
                    url: "/pages/books/",
                    data: filter
                });
            }
        },
        fields: [
            { name: "id", title: "ID", type: "number", width: 60 },
            { name: "name", title: "Название книги", type: "text", width: 110, validate: "required" },
            { name: "authors", title: "Авторы", type: "text", width: 100, validate: "required" },
            { name: "categories", title: "Направление", type: "text", width: 130, validate: "required" },
            { name: "publish", title: "Издательство", type: "text", width: 110, validate: "required" },
            { name: "date_create", title: "Дата издания", type: "text", width: 70, validate: "required" },
            { name: "number_pages", title: "Количество страниц", type: "number", width: 95, validate: "required" },
            { type: "control", deleteButton: false, editButton: false }
        ]
    });

});