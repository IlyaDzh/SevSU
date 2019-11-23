const mysql = require('mysql');

var connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '',
    database: 'library_db'
});

connection.connect(function (err) {
    if (err) {
        console.log('==============================');
        console.error('error connecting: ' + err.message);
        console.log('==============================');
        return;
    }
    console.log('==============================');
    console.log('connected: ' + connection.config.database);
    console.log('==============================');
});