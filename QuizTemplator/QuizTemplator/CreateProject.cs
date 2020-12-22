using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QuizTemplator
{
    public partial class CreateProject : Form
    {
        FolderBrowserDialog Dir = new FolderBrowserDialog();

        public CreateProject()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //string projectName = textBox1.Text;
            Form2 F2 = new Form2(Dir.SelectedPath);
            F2.Show();
            Hide();
        }

        private void CreateProject_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Dir.ShowDialog();
        }

        private void CreateProject_Load(object sender, EventArgs e)
        {

        }
    }
}
