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
    public partial class Form2 : Form
    {
        // -----  Глобальные переменные  -----

        string projectPath;
        int numSlides;

        // -----  !Глобальные переменные  -----

        // -----  Глобальные функции  -----

        void CopyFolder(string upd, string dest)
        {

            if (!System.IO.Directory.Exists(dest))
                System.IO.Directory.CreateDirectory(dest);

            string[] files = System.IO.Directory.GetFiles(upd);

            foreach (string file in files)
                System.IO.File.Copy(file, System.IO.Path.Combine(dest, System.IO.Path.GetFileName(file)), overwrite: true);

            string[] folders = System.IO.Directory.GetDirectories(upd);

            foreach (string folder in folders)
                CopyFolder(folder, System.IO.Path.Combine(dest, System.IO.Path.GetFileName(folder)));
        }

        // -----  !Глобальные функции  -----

        class QuizBuilder
        {

            public QuizBuilder()
            {

            }
        }

        public Form2(string projectName)
        {
            InitializeComponent();
            projectPath = projectName;
            CopyFolder("C:\\Users\\Danil\\Desktop\\template", projectPath);
            webBrowser1.Navigate(new Uri(projectPath + @"/index.html"));
        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            webBrowser1.Navigate(new Uri(projectPath + @"/index.html"));
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void linkLabel1_Click(object sender, EventArgs e)
        {
            this.linkLabel1.LinkVisited = true;
            System.Diagnostics.Process.Start(projectPath + @"/index.html");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            TextForm TextF = new TextForm(numSlides);
            TextF.Show();
            Hide();
        }
    }
}
