using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace _3lab_makin
{
    public partial class Form1 : Form
    {
        public String s1;
        public String s2;
        public int corKoefOut;
        public char c0;
        static SerialPort serialPort1;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            serialPort1 = new SerialPort();
            serialPort1.Open();
            serialPort1.ReadTimeout = 500;
            serialPort1.WriteTimeout = 500;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            corKoefOut = Convert.ToInt32(textBox3.Text);
            s1 = "#010" + '\r';
            serialPort1.Write(s1);
            s2 = "";
            while ((c0 = (char)serialPort1.ReadChar()) != '\r')
            {
                s2 += c0;
            }
            label1.Text = Convert.ToString(Convert.ToInt32(s2) * corKoefOut);
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            serialPort1.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            s1 = textBox1.Text + '\r';
            serialPort1.Write(s1);
            s2 = "";
            while ((c0 = (char)serialPort1.ReadChar()) != '\r')
            {
                s2 += c0;
            }
            if (s2 != "")
                MessageBox.Show("Опрос отправлен!");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            corKoefOut = Convert.ToInt32(textBox3.Text);
            s1 = "#011" + '\r';
            serialPort1.Write(s1);
            s2 = "";
            while ((c0 = (char)serialPort1.ReadChar()) != '\r')
            {
                s2 += c0;
            }
            label1.Text = Convert.ToString(Convert.ToInt32(s2) * corKoefOut);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            corKoefOut = Convert.ToInt32(textBox3.Text);
            s1 = "#012" + '\r';
            serialPort1.Write(s1);
            s2 = "";
            while ((c0 = (char)serialPort1.ReadChar()) != '\r')
            {
                s2 += c0;
            }
            label1.Text = Convert.ToString(Convert.ToInt32(s2) * corKoefOut);
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
    }
}
