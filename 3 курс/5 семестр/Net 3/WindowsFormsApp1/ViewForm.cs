using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class ViewForm : Form
    {
        public ViewForm(Form main)
        {
            InitializeComponent();

            var list = ((ListView)main.Controls["listView1"]).SelectedItems[0];

            studentLabel.Text += $" {list.SubItems[0].Text} {list.SubItems[1].Text}";
            markLabel.Text += " " + list.SubItems[3].Text;
            dateLabel.Text += " " + list.SubItems[2].Text;
            q1Label.Text += " " + list.SubItems[4].Text;
            q2Label.Text += " " + list.SubItems[5].Text;
            q3Label.Text += " " + list.SubItems[6].Text;
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
        }
    }
}