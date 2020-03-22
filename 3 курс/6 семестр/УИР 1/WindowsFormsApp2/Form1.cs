﻿using System;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        string writePath = @"D:\test.txt";
        AVLTree<int> avltree;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            drawListFromFile();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            if (Regex.IsMatch(textBox1.Text, @"^\d+$") && textBox2.Text != "" && textBox3.Text != "" && Regex.IsMatch(textBox4.Text, @"^\d+$"))
            {
                string[] row = { textBox1.Text, textBox2.Text, textBox3.Text, textBox4.Text };

                avltree.Insert(Convert.ToInt32(row[0]));

                var listViewItem = new ListViewItem(row);

                Stopwatch sWatch = new Stopwatch();
                sWatch.Start();
                listView.Items.Add(listViewItem);
                sWatch.Stop();
                MessageBox.Show(sWatch.ElapsedMilliseconds.ToString());

                clearFields();
                saveListInFile();
            }
            else
            {
                MessageBox.Show("Ошибка в полях ввода!", "Добавление", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void buttonEdit_Click(object sender, EventArgs e)
        {
            if (Regex.IsMatch(textBox1.Text, @"^\d+$") && textBox2.Text != "" && textBox3.Text != "" && Regex.IsMatch(textBox4.Text, @"^\d+$"))
            {
                listView.SelectedItems[0].Remove();

                string[] row = { textBox1.Text, textBox2.Text, textBox3.Text, textBox4.Text };
                var listViewItem = new ListViewItem(row);
                listView.Items.Add(listViewItem);

                clearFields();
                saveListInFile();
                listView.Items.Clear();
                drawListFromFile();
            }
            else
            {
                MessageBox.Show("Ошибка в полях ввода!", "Редактирование", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void buttonSearch_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "")
            {
                listView.Items.Clear();
                drawListFromFile();
                return;
            }

            try
            {
                Stopwatch sWatch = new Stopwatch();
                sWatch.Start();
                avltree.Find(Convert.ToInt32(textBox1.Text));
                sWatch.Stop();
                MessageBox.Show(sWatch.ElapsedMilliseconds.ToString());

                var searchResult = avltree.Find(Convert.ToInt32(textBox1.Text));

                if (searchResult.value == Convert.ToInt32(textBox1.Text))
                {
                    for (int i = 0; i < listView.Items.Count; i++)
                    {
                        var item = listView.Items[i];
                        if (item.Text == textBox1.Text)
                        {
                            listView.Items.Clear();
                            listView.Items.Add(item);
                        }
                    }
                }
            }
            catch
            {
                MessageBox.Show("Ничего не найдено!", "Поиск", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (Regex.IsMatch(textBox1.Text, @"^\d+$"))
            {
                bool deleted = false;
                for (int i = 0; i < listView.Items.Count; i++)
                {
                    var item = listView.Items[i];
                    if (item.Text == textBox1.Text)
                    {
                        deleted = true;
                        listView.Items.Remove(item);
                        clearFields();
                        saveListInFile();
                        listView.Items.Clear();
                        drawListFromFile();
                    }
                }
                if (!deleted)
                {
                    MessageBox.Show("Нет такой строки для удаления!", "Удаление", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            else
            {
                MessageBox.Show("Поле Счет должно быть числовым!", "Удаление", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void clearFields()
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
        }

        private void drawListFromFile()
        {
            avltree = new AVLTree<int>();

            string[] lines = File.ReadAllLines(@"D:\new.txt", Encoding.Default);
            foreach (string line in lines)
            {
                string[] items = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                listView.Items.Add(new ListViewItem(items));
                avltree.Insert(Convert.ToInt32(items[0]));
            }
        }

        private void saveListInFile()
        {
            using (var tw = new StreamWriter(@"D:\new.txt", false, Encoding.Default))
            {
                foreach (ListViewItem item in listView.Items)
                {
                    tw.WriteLine("{0} {1} {2} {3}", item.SubItems[0].Text, item.SubItems[1].Text, item.SubItems[2].Text, item.SubItems[3].Text);
                }
            }
        }

        private void listView_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listView.SelectedItems.Count > 0)
            {
                textBox1.Text = listView.SelectedItems[0].SubItems[0].Text;
                textBox2.Text = listView.SelectedItems[0].SubItems[1].Text;
                textBox3.Text = listView.SelectedItems[0].SubItems[2].Text;
                textBox4.Text = listView.SelectedItems[0].SubItems[3].Text;
            }
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            clearFields();
        }

        private void buttonResult_Click(object sender, EventArgs e)
        {
            if (listView.Items.Count != 0)
                avltree.PrintDot(writePath);
        }
    }
}