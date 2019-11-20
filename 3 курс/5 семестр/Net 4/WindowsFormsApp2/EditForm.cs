using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class EditForm : Form
    {
        public Exam Result;
        public string imageName;

        public EditForm(Exam main)
        {
            InitializeComponent();

            firstNameTextBox.Text = main.FirstName;
            lastNameTextBox.Text = main.LastName;
            markTextBox.Text = main.Mark.ToString();
            questionsTextBox.Text = main.Questions;
            pictureBox.Image = Image.FromFile(main.Photo);
            pictureBox.ImageLocation = main.Photo;
        }

        private void pictureBox_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                imageName = dialog.FileName;
                try
                {
                    pictureBox.Image = Image.FromFile(imageName);
                    pictureBox.ImageLocation = imageName;
                }
                catch (OutOfMemoryException) { return; }
            }
        }

        private void editButton_Click(object sender, EventArgs e)
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
                questionsTextBox.Text,
                pictureBox.ImageLocation
            );

            DialogResult = DialogResult.OK;
            Close();
        }
    }
}