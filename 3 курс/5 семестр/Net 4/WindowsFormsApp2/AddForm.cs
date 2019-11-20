using System;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class AddForm : Form
    {
        public Exam Result;

        public AddForm()
        {
            InitializeComponent();
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            if (lastNameTextBox.Text == "" ||
                firstNameTextBox.Text == "" ||
                markTextBox.Text == "" ||
                questionsTextBox.Text == "")
            {
                MessageBox.Show("Необходимо заполнить все поля!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (MainForm.IsInt(lastNameTextBox.Text) ||
                MainForm.IsInt(firstNameTextBox.Text))
            {
                MessageBox.Show("В поле 'Фамилия' или 'Имя' содержатся цифры!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            try
            {
                Convert.ToInt32(markTextBox.Text);
            }
            catch
            {
                MessageBox.Show("Поле 'Оценка' введено не верно!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            Result = new Exam(
                firstNameTextBox.Text,
                lastNameTextBox.Text,
                DateTime.Now,
                Convert.ToInt32(markTextBox.Text),
                questionsTextBox.Text
            );

            DialogResult = DialogResult.OK;
            Close();
        }
    }
}