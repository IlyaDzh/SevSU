using System;
using System.Diagnostics;
using System.IO;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        private readonly string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"..\..\file.txt");
        private HashTable hashTable = new HashTable();
        private Stopwatch sWatch = new Stopwatch();

        public Form1()
        {
            InitializeComponent();

            readFile();
            fillDataHashFromMemory();
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

        private void fillDataHashFromMemory()
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

        private void removeFromFile()
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
        }

        private bool findInFile()
        {
            string[] lines = File.ReadAllLines(path);
            string[] values;

            for (int i = 0; i < lines.Length; i++)
            {
                values = lines[i].ToString().Split('\t');

                if (values[0] == textBoxSearchSubscriber.Text)
                {
                    return true;
                }
            }

            return false;
        }

        private void resetAllFields()
        {
            textBoxSubscriber.Text = "";
            textBoxPhone.Text = "";
            textBoxHome.Text = "";
            textBoxSum.Text = "";
        }

        private void setTimeLog(string title, string time)
        {
            textBoxLog.Text += title + time + "\r\n";

            textBoxLog.SelectionStart = textBoxLog.Text.Length;
            textBoxLog.ScrollToCaret();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            if (textBoxSubscriber.Text == "") return;

            string[] row = new string[] { textBoxSubscriber.Text, textBoxPhone.Text, textBoxHome.Text, textBoxSum.Text };

            // ДОБАВЛЕНИЕ В ХЕШ-ТАБЛИЦУ
            sWatch.Start();
            hashTable.Insert(row[0], row[1]);
            sWatch.Stop();
            setTimeLog("Добавление в хеш-таблицу: ", sWatch.ElapsedTicks.ToString());
            sWatch.Reset();

            // ДОБАВЛЕНИЕ В ОСНОВНУЮ ТАБЛИЦУ
            sWatch.Start();
            appendToFile(row);
            sWatch.Stop();
            setTimeLog("Добавление в основную таблицу: ", sWatch.ElapsedTicks.ToString());
            sWatch.Reset();

            dataGridViewFile.Rows.Add(row);

            fillDataHashFromMemory();

            resetAllFields();
        }

        private void buttonRemove_Click(object sender, EventArgs e)
        {
            if (textBoxSubscriber.Text == "") return;

            // УДАЛЕНИЕ ИЗ ХЕШ-ТАБЛИЦЫ
            sWatch.Start();
            hashTable.Delete(textBoxSubscriber.Text);
            sWatch.Stop();
            setTimeLog("Удаление из хеш-таблицы: ", sWatch.ElapsedTicks.ToString());
            sWatch.Reset();

            foreach (DataGridViewRow item in dataGridViewFile.Rows)
            {
                if (item.Cells["Column1"].Value != null && item.Cells["Column1"].Value.ToString() == textBoxSubscriber.Text.ToString())
                {
                    dataGridViewFile.Rows.RemoveAt(item.Index);
                }
            }

            // УДАЛЕНИЕ ИЗ ОСНОВНОЙ ТАБЛИЦЫ
            sWatch.Start();
            removeFromFile();
            sWatch.Stop();
            setTimeLog("Удаление из основной таблицы: ", sWatch.ElapsedTicks.ToString());
            sWatch.Reset();

            fillDataHashFromMemory();

            resetAllFields();
        }

        private void buttonSearch_Click(object sender, EventArgs e)
        {
            if (textBoxSearchSubscriber.Text == "") return;

            // ПОИСК В ХЕШ-ТАБЛИЦЕ
            sWatch.Start();
            hashTable.Search(textBoxSearchSubscriber.Text);
            sWatch.Stop();
            setTimeLog("Поиск в хеш-таблице: ", sWatch.ElapsedTicks.ToString());
            sWatch.Reset();

            // ПОИСК В ОСНОВНОЙ ТАБЛИЦЕ
            sWatch.Start();
            findInFile();
            sWatch.Stop();
            setTimeLog("Поиск в основной таблице: ", sWatch.ElapsedTicks.ToString());
            sWatch.Reset();

            foreach (DataGridViewRow row in dataGridViewFile.Rows)
            {
                if (row.Cells["Column1"].Value != null && row.Cells["Column1"].Value.ToString() == textBoxSearchSubscriber.Text)
                {
                    row.Selected = true;
                }
            }

            foreach (DataGridViewRow row in dataGridViewHash.Rows)
            {
                if (row.Cells["Key"].Value != null && row.Cells["Key"].Value.ToString() == textBoxSearchSubscriber.Text)
                {
                    row.Selected = true;
                }
            }
        }

        private void buttonReset_Click(object sender, EventArgs e)
        {
            textBoxSearchSubscriber.Text = "";
        }

        private void dataGridViewFile_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                DataGridViewRow row = dataGridViewFile.Rows[e.RowIndex];
                if (row.Cells["Column1"].Value != null)
                {
                    textBoxSubscriber.Text = row.Cells["Column1"].Value.ToString();
                }
            }
        }
    }
}
