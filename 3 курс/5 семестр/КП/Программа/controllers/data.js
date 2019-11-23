var test = [];

connection.query('SELECT * FROM `система_выдачи`', function (error, results, fields) {
    console.log(results);
    test = results;
});

var clients = [
    { "Name": "Otto Clay", "Age": 25, "Country": 1, "Address": "Ap #897-1459 Quam Avenue", "Married": false },
    { "Name": "Connor Johnston", "Age": 45, "Country": 2, "Address": "Ap #370-4647 Dis Av.", "Married": true },
    { "Name": "Lacey Hess", "Age": 29, "Country": 3, "Address": "Ap #365-8835 Integer St.", "Married": false },
    { "Name": "Timothy Henson", "Age": 56, "Country": 1, "Address": "911-5143 Luctus Ave", "Married": true },
    { "Name": "Ramona Benton", "Age": 32, "Country": 3, "Address": "Ap #614-689 Vehicula Street", "Married": false }
];

var countries = [
    { Name: "", Id: 0 },
    { Name: "United States", Id: 1 },
    { Name: "Canada", Id: 2 },
    { Name: "United Kingdom", Id: 3 }
];

$("#jsGrid").jsGrid({
    width: "100%",
    height: "400px",

    editing: true,
    sorting: true,
    inserting: true,
    filtering: true,

    // selecting: true,
    // paging: true,
    // autoload: true,
    // pageLoading: true,

    // pageSize: 15,
    // pageButtonCount: 5,

    controller: {
        loadData: function (filter) {
            console.log(filter)
        },
        deleteItem: function (item) {
            console.log(item)
        },
        insertItem: function (item) {
            console.log(item)
        },
        updateItem: function (item) {
            console.log(item)
        }
    },

    data: clients,

    fields: [
        { name: "Name", type: "text", width: 150, validate: "required" },
        { name: "Age", type: "number", width: 50 },
        { name: "Address", type: "text", width: 200 },
        { name: "Country", type: "select", items: countries, valueField: "Id", textField: "Name" },
        { name: "Married", type: "checkbox", title: "Is Married" },
        { type: "control" }
    ]
});