$(function () {

    var genders = [
        { gender: "", id: 0 },
        { gender: "мужчина", id: 1 },
        { gender: "женщина", id: 2 }
    ];

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
        deleteConfirm: "Вы действительно хотите удалить читателя?",
        controller: {
            loadData: function (filter) {
                return $.ajax({
                    type: "GET",
                    url: "/pages/readers/",
                    data: filter
                });
            },
            insertItem: function (item) {
                return $.ajax({
                    type: "POST",
                    url: "/pages/readers/",
                    data: item
                });
            },
            updateItem: function (item) {
                return $.ajax({
                    type: "PUT",
                    url: "/pages/readers/",
                    data: item
                });
            },
            deleteItem: function (item) {
                return $.ajax({
                    type: "DELETE",
                    url: "/pages/readers/",
                    data: item
                });
            }
        },
        fields: [
            { name: "id", title: "ID", type: "number", width: 20 },
            { name: "name", title: "ФИО", type: "text", width: 115, validate: "required" },
            {
                name: "date", title: "Дата рождения", type: "text", width: 45,
                validate: function (value, item) {
                    return /^(19[0-9]{2}|2[0-9]{3})\-(0[1-9]|1[0-2])\-(0[1-9]|1[0-9]|2[0-9]|3[0-1])$/.test(value);
                }
            },
            { name: "gender", title: "Пол", type: "select", width: 75, items: genders, valueField: "gender", textField: "gender", validate: "required", filtering: false },
            { name: "tel", title: "Телефон", type: "text", width: 55, validate: "required" },
            { name: "address", title: "Адрес", type: "text", width: 75, validate: "required" },
            { type: "control" }
        ]
    });

});