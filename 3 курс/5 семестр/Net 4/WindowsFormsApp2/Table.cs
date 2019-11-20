using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Table : Form
    {
        public BindingList<Exam> exams = new BindingList<Exam>();
        public DataGridView DataGridView { get { return dataGridView1; } }

        public Table()
        {
            InitializeComponent();

            dataGridView1.DataSource = exams;

            Closing += (sender, e) =>
            {
                MainForm c = (MainForm) MdiParent;
                c.windowNumber--;
            };
        }

        public Table(IEnumerable<Exam> examsCollection) : this()
        {
            foreach (Exam field in examsCollection)
            {
                exams.Add(field);
            }
        }
    }
}