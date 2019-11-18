using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class MainForm : Form
    {
        private List<Exam> exams = new List<Exam>();

        public MainForm()
        {
            InitializeComponent();
        }

        private void UpdateList()
        {
            listView1.Items.Clear();

            foreach (Exam exam in exams)
            {
                listView1.Items.Add(new ListViewItem(new string[] {
                    exam.LastName,
                    exam.FirstName,
                    exam.Date.ToString(),
                    exam.Mark.ToString(),
                    exam.Questions[0],
                    exam.Questions[1],
                    exam.Questions[2]
                }));
            }
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
            if (listView1.SelectedIndices.Count == 0)
            {
                MessageBox.Show("Выберите студента для просмотра!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            ViewForm viewForm = new ViewForm(this);

            viewForm.ShowDialog();
        }

        private void добавитьToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            AddForm addForm = new AddForm();

            if (addForm.ShowDialog() == DialogResult.OK)
            {
                exams.Add(new Exam(
                    ((TextBox)addForm.Controls["firstNameTextBox"]).Text,
                    ((TextBox)addForm.Controls["lastNameTextBox"]).Text,
                    DateTime.Now,
                    Convert.ToInt32(((TextBox)addForm.Controls["markTextBox"]).Text),
                    new string[] {
                        ((TextBox)addForm.Controls["q1TextBox"]).Text,
                        ((TextBox)addForm.Controls["q2TextBox"]).Text,
                        ((TextBox)addForm.Controls["q3TextBox"]).Text
                    }
                ));
            }

            UpdateList();
        }

        private void удалитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedIndices.Count == 0)
            {
                MessageBox.Show("Выберите студента для удаления!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            exams.RemoveAt(listView1.SelectedIndices[0]);

            UpdateList();
        }

        private void редактироватьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedIndices.Count == 0)
            {
                MessageBox.Show("Выберите студента для редактирования!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            EditForm editForm = new EditForm(this);

            if (editForm.ShowDialog() == DialogResult.OK)
            {
                exams.RemoveAt(listView1.SelectedIndices[0]);
                exams.Insert(listView1.SelectedIndices[0], new Exam(
                    ((TextBox)editForm.Controls["firstNameTextBox"]).Text,
                    ((TextBox)editForm.Controls["lastNameTextBox"]).Text,
                    DateTime.Now,
                    Convert.ToInt32(((TextBox)editForm.Controls["markTextBox"]).Text),
                    new string[] {
                        ((TextBox)editForm.Controls["q1TextBox"]).Text,
                        ((TextBox)editForm.Controls["q2TextBox"]).Text,
                        ((TextBox)editForm.Controls["q3TextBox"]).Text
                    }
                ));
            }

            UpdateList();
        }

        private void оПрограммеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Лабораторная работа №3 \nGitHub: https://github.com/ilyadzh", "О программе", MessageBoxButtons.OK, MessageBoxIcon.Asterisk, MessageBoxDefaultButton.Button1);
        }
    }
}