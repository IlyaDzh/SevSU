$(function () {

    $("#jsGrid").jsGrid({
        height: "70%",
        width: "100%",
        filtering: true,
        sorting: true,
        paging: true,
        autoload: true,
        pageSize: 9,
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
                    url: "/pages/publish/",
                    data: filter
                });
            }
        },
        fields: [
            { name: "id", title: "ID", type: "number", width: 60 },
            { name: "name", title: "Название", type: "text", width: 175, validate: "required" },
            { name: "address", title: "Адрес", type: "text", width: 175, validate: "required" },
            { type: "control", deleteButton: false, editButton: false }
        ]
    });

});