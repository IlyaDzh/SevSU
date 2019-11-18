using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class AddForm : Form
    {
        public AddForm()
        {
            InitializeComponent();
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            if (lastNameTextBox.Text == "" || 
                firstNameTextBox.Text == "" ||
                markTextBox.Text == "" ||
                q1TextBox.Text == "" ||
                q2TextBox.Text == "" ||
                q3TextBox.Text == "")
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

            DialogResult = DialogResult.OK;
        }
    }
}