const express = require("express");
const mysql = require("mysql2/promise");
const now = require("performance-now");

const server_host = "localhost";
const server_port = "3000";

const conn = {
    host: "localhost",
    database: "lab4",
    user: "root",
    password: "root"
};

const test_id = 100;
const queries = [
    {
        table: "transactions_no_part_200",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_no_part_200 LIMIT 1`
    },

    {
        table: "transactions_no_part_200",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_no_part_200 WHERE id = ${test_id} LIMIT 1`
    },

    {
        table: "transactions_part_200",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_part_200 LIMIT 1`
    },

    {
        table: "transactions_part_200",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_part_200 WHERE id = ${test_id} LIMIT 1`
    },

    {
        table: "transactions_no_part_700",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_no_part_700 LIMIT 1`
    },

    {
        table: "transactions_no_part_700",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_no_part_700 WHERE id = ${test_id} LIMIT 1`
    },

    {
        table: "transactions_part_700",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_part_700 LIMIT 1`
    },

    {
        table: "transactions_part_700",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_part_700 WHERE id = ${test_id} LIMIT 1`
    },

    {
        table: "transactions_no_part_1300",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_no_part_1300 LIMIT 1`
    },

    {
        table: "transactions_no_part_1300",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_no_part_1300 WHERE id = ${test_id} LIMIT 1`
    },

    {
        table: "transactions_part_1300",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_part_1300 LIMIT 1`
    },

    {
        table: "transactions_part_1300",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_part_1300 WHERE id = ${test_id} LIMIT 1`
    },

    {
        table: "transactions_no_part_1900",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_no_part_1900 LIMIT 1`
    },

    {
        table: "transactions_no_part_1900",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_no_part_1900 WHERE id = ${test_id} LIMIT 1`
    },

    {
        table: "transactions_part_1900",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_part_1900 LIMIT 1`
    },

    {
        table: "transactions_part_1900",
        sql: `SELECT SQL_NO_CACHE * FROM transactions_part_1900 WHERE id = ${test_id} LIMIT 1`
    }
];

async function run() {
    const db = await mysql.createConnection(conn);
    const app = express();

    app.set("view engine", "pug");

    app.get(
        "/",
        wrapAsync(async (req, res, next) => {
            let results = [];
            for (let i in queries) {
                const [row] = await db.execute(
                    `SELECT COUNT(*) AS n FROM ${queries[i].table}`
                );

                start_time = now();
                const rows = await db.execute(queries[i].sql);
                end_time = now();

                results.push({
                    n: row[0].n,
                    sql: queries[i].sql,
                    table: queries[i].table,
                    time: String((end_time - start_time).toFixed(3))
                });
            }

            res.render("results", { header: `Query results`, results: results });
        })
    );

    app.listen(server_port, server_host, () => {
        console.log(`Server running at http://${server_host}:${server_port}/`);
    });
}

function wrapAsync(fn) {
    return function (req, res, next) {
        fn(req, res, next).catch(next);
    };
}

run();
