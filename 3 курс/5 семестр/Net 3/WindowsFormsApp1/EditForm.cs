using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class EditForm : Form
    {
        public EditForm(Form main)
        {
            InitializeComponent();

            var list = ((ListView)main.Controls["listView1"]).SelectedItems[0];

            firstNameTextBox.Text += list.SubItems[1].Text;
            lastNameTextBox.Text += list.SubItems[0].Text;
            markTextBox.Text += list.SubItems[3].Text;
            q1TextBox.Text += list.SubItems[4].Text;
            q2TextBox.Text += list.SubItems[5].Text;
            q3TextBox.Text += list.SubItems[6].Text;
        }

        private void editButton_Click(object sender, EventArgs e)
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