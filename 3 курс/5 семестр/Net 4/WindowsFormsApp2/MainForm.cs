using System;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class MainForm : Form
    {
        public int windowNumber { get; set; } = 0;

        public MainForm()
        {
            InitializeComponent();
        }

        public static bool IsInt(string str)
        {
            foreach (char c in str)
            {
                if (c < '0' || c > '9')
                    return false;
            }

            return true;
        }

        private void посмотретьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (ActiveMdiChild == null)
            {
                MessageBox.Show("Не открыто ни одной формы!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                return;
            }
            Table table = (Table)ActiveMdiChild;
            Exam t = (Exam)table.DataGridView.CurrentRow?.DataBoundItem;
            if (t != null)
            {
                ViewForm viewForm = new ViewForm(t);
                viewForm.ShowDialog();
            }
            else
            {
                MessageBox.Show("Не выбран студент!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Hand);
            }
        }

        private void добавитьToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            AddForm addForm = new AddForm();
            DialogResult result = addForm.ShowDialog();
            if (result == DialogResult.OK && addForm.Result != null)
            {
                if (ActiveMdiChild == null)
                {
                    новаяТаблицаToolStripMenuItem_Click(sender, e);
                }

                var table = (Table)ActiveMdiChild;
                table?.exams.Add(addForm.Result);
            }
        }

        private void удалитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (ActiveMdiChild == null)
            {
                MessageBox.Show("Не открыто ни одной формы!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                return;
            }
            Table table = (Table)ActiveMdiChild;
            var currentRow = table.DataGridView.CurrentRow;
            Exam t = (Exam)currentRow?.DataBoundItem;
            if (t != null)
            {
                table.exams.Remove(t);
            }
            else
            {
                MessageBox.Show("Не выбран студент!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Hand);
            }
        }

        private void редактироватьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (ActiveMdiChild == null)
            {
                MessageBox.Show("Не открыто ни одной формы", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                return;
            }
            Table table = (Table)ActiveMdiChild;
            Exam t = (Exam)table.DataGridView.CurrentRow?.DataBoundItem;
            if (t != null)
            {
                int index = table.exams.IndexOf(t);
                using (EditForm editForm = new EditForm(t))
                {
                    var result = editForm.ShowDialog();
                    if (result == DialogResult.OK)
                    {
                        table.exams[index] = editForm.Result;
                    }
                }
            }
            else
            {
                MessageBox.Show("Не выбран студент!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Hand);
            }
        }

        private void оПрограммеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Лабораторная работа №4 \nGitHub: https://github.com/ilyadzh", "О программе", MessageBoxButtons.OK, MessageBoxIcon.Asterisk, MessageBoxDefaultButton.Button1);
        }

        private void новаяТаблицаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Table table = new Table();
            windowNumber++;
            table.MdiParent = this;
            table.Text = "Таблица №" + windowNumber;
            table.Show();
        }

        private void открытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                Exam[] fields;
                try
                {
                    BinaryFormatter formatter = new BinaryFormatter();
                    FileStream fs = File.Open(dialog.FileName, FileMode.OpenOrCreate);

                    fields = (Exam[])formatter.Deserialize(fs);
                }
                catch (IOException)
                {
                    return;
                }
                catch (InvalidCastException)
                {
                    MessageBox.Show("Неверный тип файла", "Ошибка!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                catch (SerializationException)
                {
                    MessageBox.Show("Неверный тип файла", "Ошибка!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                Table table = new Table(fields);
                windowNumber++;
                table.MdiParent = this;
                table.Text = "Таблица №" + windowNumber;
                table.Show();
            }
        }

        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (ActiveMdiChild == null)
            {
                MessageBox.Show("Не открыто ни одной таблицы!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                return;
            }
            SaveFileDialog dialog = new SaveFileDialog();
            Table table = (Table)ActiveMdiChild;
            dialog.Filter = "dat-файл(*.dat)|*.dat";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                BinaryFormatter formatter = new BinaryFormatter();
                FileStream fs = File.Open(dialog.FileName, FileMode.OpenOrCreate);

                formatter.Serialize(fs, table.exams.ToArray());
                fs.Close();
            }
        }

        private void выбратьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (ActiveMdiChild == null)
            {
                MessageBox.Show("Не открыто ни одной формы!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                return;
            }

            SelectForm selectForm = new SelectForm((Table)ActiveMdiChild);
            DialogResult result = selectForm.ShowDialog();
            if (result == DialogResult.OK)
            {
                Table tableSelect = new Table();
                tableSelect.MdiParent = this;
                tableSelect.Text = "Выборка";
                tableSelect.Show();
                tableSelect.DataGridView.DataSource = selectForm.results;
            }
        }
    }
}