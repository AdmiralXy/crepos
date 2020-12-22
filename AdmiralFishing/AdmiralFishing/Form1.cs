using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;

namespace AdmiralFishing
{
    public partial class Form1 : Form
    {
        // Таргет процесс
        private const string processName = "GTA5";
        private Process process;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Memory.GetProcessesByName(processName, out process);
            IntPtr handle = Memory.OpenProcess(process.Id);
            int pointerPlayer = Memory.Read<int>(Offsets.baseGame + Offsets.ptrPlayerEntity);
            Memory.Read<int>(pointerPlayer + Offsets.health);

            label1.Text = Convert.ToString(Memory.ReadString(0x18E81EFCD23, sizeof(ulong)));
        }


        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            Memory.CloseProcess();
        }
    }
}
