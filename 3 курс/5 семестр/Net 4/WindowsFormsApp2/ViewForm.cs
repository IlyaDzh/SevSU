using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class ViewForm : Form
    {
        public Exam Result;
        public ViewForm(Exam main)
        {
            InitializeComponent();

            studentLabel.Text += $" {main.LastName} {main.FirstName}";
            markLabel.Text += " " + main.Mark;
            dateLabel.Text += " " + main.Date;
            questionsLabel.Text += " " + main.Questions;
            pictureBox.Image = Image.FromFile(main.Photo);
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
        }
    }
}