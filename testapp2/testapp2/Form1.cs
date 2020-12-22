using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace testapp2
{
    public partial class Form1 : Form
    {
        static int A = 100;
        static string bash = "100 Долларов";

        public Form1()
        {
            InitializeComponent();
            label2.Text = bash;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Random random = new Random();
            A = random.Next(0, 100);
            label1.Text = Convert.ToString(A);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (A != Convert.ToInt32(label1.Text))
            {
                label1.Text = Convert.ToString(A);
                label2.Text = bash;
                label2.Update();
            }
            label1.Update();
        }
    }
}
