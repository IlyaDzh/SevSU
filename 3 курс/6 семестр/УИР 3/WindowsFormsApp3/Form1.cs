﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        private readonly string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"..\..\file.txt");
        private HashTable hashTable = new HashTable();

        public Form1()
        {
            InitializeComponent();

            readFile();
            setDataGridHash();
        }

        private void readFile()
        {
            dataGridViewFile.Rows.Clear();
            string[] lines = File.ReadAllLines(path);
            string[] values;

            for (int i = 0; i < lines.Length; i++)
            {
                values = lines[i].ToString().Split('\t');
                string[] row = new string[values.Length];

                for (int j = 0; j < values.Length; j++)
                {
                    row[j] = values[j].Trim();
                }
                dataGridViewFile.Rows.Add(row);

                hashTable.Insert(row[0], row[1]);
            }
        }

        private void setDataGridHash()
        {
            dataGridViewHash.Rows.Clear();
            foreach (var item in hashTable.Items)
            {
                foreach (var value in item.Value)
                {
                    dataGridViewHash.Rows.Add(item.Key, value.Key);
                }
            }
        }

        //private void writeFile()
        //{
        //    StreamWriter writer = new StreamWriter(path);
        //    for (int i = 0; i < dataGridViewFile.Rows.Count - 1; i++)
        //    {
        //        for (int j = 0; j < dataGridViewFile.Columns.Count; j++)
        //        {
        //            writer.Write(dataGridViewFile.Rows[i].Cells[j].Value.ToString() + "\t");
        //        }
        //        writer.WriteLine("");
        //    }
        //    writer.Close();
        //}

        private void appendToFile(string[] row)
        {
            using (StreamWriter writer = File.AppendText(path))
            {
                for (int i = 0; i < row.Length; i++)
                {
                    writer.Write(row[i] + "\t");
                }
                writer.WriteLine("");
            }
        }

        private void resetAllFields()
        {
            textBoxSubscriber.Text = "";
            textBoxPhone.Text = "";
            textBoxHome.Text = "";
            textBoxSum.Text = "";
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            string[] row = new string[] { textBoxSubscriber.Text, textBoxPhone.Text, textBoxHome.Text, textBoxSum.Text };

            hashTable.Insert(row[0], row[1]);

            dataGridViewFile.Rows.Add(row);
            appendToFile(row);

            resetAllFields();

            setDataGridHash();
        }

        private void buttonRemove_Click(object sender, EventArgs e)
        {
            string[] lines = File.ReadAllLines(path);
            using (StreamWriter writer = new StreamWriter(path))
            {
                foreach (string line in lines)
                {
                    string[] words = line.Split('\t');
                    if (words[0] != textBoxSubscriber.Text)
                    {
                        writer.WriteLine(line);
                    }
                }
            }

            readFile();
            resetAllFields();
        }
    }
}
