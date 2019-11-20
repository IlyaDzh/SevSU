using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class SelectForm : Form
    {
        public Exam Result;
        public List<Exam> results = new List<Exam>();
        private readonly Table _active;

        public SelectForm(Table active)
        {
            InitializeComponent();

            _active = active;
        }

        private void selectButton_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < _active.DataGridView.RowCount; i++)
            {
                if (_active.DataGridView.Rows[i].Cells[0].Value.ToString().Contains(firstNameTextBox.Text) &&
                    _active.DataGridView.Rows[i].Cells[1].Value.ToString().Contains(lastNameTextBox.Text) &&
                    _active.DataGridView.Rows[i].Cells[3].Value.ToString().Contains(markTextBox.Text) &&
                    _active.DataGridView.Rows[i].Cells[4].Value.ToString().Contains(questionsTextBox.Text))
                {
                    Exam Result = new Exam(
                       _active.DataGridView.Rows[i].Cells[0].Value.ToString(),
                       _active.DataGridView.Rows[i].Cells[1].Value.ToString(),
                       Convert.ToDateTime(_active.DataGridView.Rows[i].Cells[2].Value),
                       Convert.ToInt32(_active.DataGridView.Rows[i].Cells[3].Value),
                       _active.DataGridView.Rows[i].Cells[4].Value.ToString()
                    );
                    results.Add(Result);
                }
            }

            DialogResult = DialogResult.OK;
            Close();
        }
    }
}