using System;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace Notepad
{
    public partial class Form1 : Form
    {
        string fileName = "";
        bool filesave = false;

        public Form1()
        {
            InitializeComponent();
        }

        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Saving(fileName);
            }
            catch { }
        }

        private void открытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Saving(fileName);
            }
            catch { }

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.Clear();
                openFileDialog1.Filter = "Text Files (*.txt)|*.txt";
                fileName = openFileDialog1.FileName;
                textBox1.Text = File.ReadAllText(fileName, Encoding.GetEncoding(1251));
                Text = fileName;
            }
        }

        private void сохранитьКакToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialog1.Filter = "Text Files|*.txt";
            saveFileDialog1.DefaultExt = ".txt";
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                var nameNew = saveFileDialog1.FileName;
                Saving(nameNew);
                if(fileName != "")
                    Saving(fileName);
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (filesave)
            {
                e.Cancel = false;
                return;
            }

            if (fileName == "" && textBox1.Text != "")
                e.Cancel = MessageBox.Show("Вы хотите выйти не сохранив?", "Выход", MessageBoxButtons.YesNo, MessageBoxIcon.Information) == DialogResult.No;

            if (fileName != "" && textBox1.Text != File.ReadAllText(fileName))
                e.Cancel = MessageBox.Show("Вы хотите выйти не сохранив?", "Выход", MessageBoxButtons.YesNo, MessageBoxIcon.Information) == DialogResult.No;
        }

        void Saving(string fileSaving)
        {
            File.WriteAllText(fileSaving, textBox1.Text, Encoding.GetEncoding(1251));
            filesave = true;
        }

        private void toolStripButton_Opt_Click(object sender, EventArgs e)
        {
            Regex regex = new Regex(@"\s+");
            textBox1.Text = regex.Replace(textBox1.Text, " ");
        }
        
        private void toolStripButton_About_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Блокнот v1.0 by IlyaD", "О программе", MessageBoxButtons.OK,
            MessageBoxIcon.Asterisk, MessageBoxDefaultButton.Button1);
        }

        private void выделитьВсёToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textBox1.SelectAll();
        }

        private void отменитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (textBox1.CanUndo == true)
                textBox1.Undo();
        }

        private void вырезатьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (textBox1.SelectedText != "")
                textBox1.Cut();
        }

        private void копироватьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (textBox1.SelectionLength > 0)
                textBox1.Copy();
        }

        private void вставитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Clipboard.ContainsText())
                textBox1.Paste();
        }

        private void удалитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (textBox1.SelectionLength > 0)
                textBox1.SelectedText = "";
        }

        private void времяИДатаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textBox1.AppendText(DateTime.Now.ToString());
        }

        private void шрифтToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (fontDialog1.ShowDialog() == DialogResult.OK)
                textBox1.Font = fontDialog1.Font;
        }

        private void цветПоляToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
                textBox1.BackColor = colorDialog1.Color;
        }

        private void создатьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if ((fileName == "" && textBox1.Text != "") || (fileName != "" && textBox1.Text != File.ReadAllText(fileName)))
            {
                DialogResult result = MessageBox.Show("Вы хотите сохранить файл?", "Сохранение", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Information);
                if (result == DialogResult.Yes)
                    Saving(fileName);
                if (result == DialogResult.Cancel)
                    return;
            }

            textBox1.Text = "";
            fileName = "";
            filesave = false;
        }

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}