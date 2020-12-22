using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using gma.System.Windows;
using System.Media;
using System.Threading;


namespace AdmiralRecoil
{
    public partial class MainWindow : Form
    {
        [DllImport("user32.dll")]
        static extern bool SetCursorPos(int X, int Y);

        [DllImport("user32.dll")]
        public static extern bool GetCursorPos(out Point p);

        [DllImport("user32.dll")]
        static extern void mouse_event(int dwFlags, int dx, int dy, int dwData, int dwExtraInfo);

        [Flags]
        public enum MouseEventFlags
        {
            LEFTDOWN = 0x00000002,
            LEFTUP = 0x00000004,
            MIDDLEDOWN = 0x00000020,
            MIDDLEUP = 0x00000040,
            MOVE = 0x00000001,
            ABSOLUTE = 0x00008000,
            RIGHTDOWN = 0x00000008,
            RIGHTUP = 0x00000010
        }

        // VARIABLES
        bool switcher = false;
        int ms_speeder = 0;
        int angle = 0;
        int speedModifier = 0;
        static int i = 0;
        static RecoilControl RecoilInterface = new RecoilControl();

        public MainWindow()
        {
            InitializeComponent();
            this.KeyPreview = true;
            textBox.Cursor = System.Windows.Forms.Cursors.Default;
            RecoilInterface.Weapon_R99();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (switcher)
            {
                switcher = false;
            }
            else
            {
                switcher = true;
            }
        }

        public class RecoilControl
        {
            int ms = 0;
            public int N = 0;
            public int speed = 0;
            public double[] angles = new double[0];
            public int[] times = new int[0];
            public double[] lenghts;
            public void Weapon_R99()
            {
                ms = 1500;
                speed = 3;
                N = 13;

                Array.Resize(ref angles, N);
                Array.Resize(ref times, N);

                Point[] steps1 = new Point[N];
                Point[] steps2 = new Point[N];

                int temp1 = 0;
                int temp2 = 0;

                steps1[temp1] = new Point(0, 0);
                steps2[temp1++] = new Point(0, 3);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(1, 9);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(-1, 12);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(-1, 20);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(-3, 24);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(-2, 27);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(-5, 30);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(-7, 35);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(-2, 41);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(-2, 47);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(-14, 48);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(2, 52);

                steps1[temp1] = steps2[temp2++];
                steps2[temp1++] = new Point(-12, 60);

                for (int i = 0; i < N; i++)
                {
                    angles[i] = Angulo(steps1[i].X, steps1[i].Y, steps2[i].X, steps2[i].Y);
                }

                lenghts = new double[N];

                for (int i = 0; i < N; i++)
                {
                    int deltaX = steps2[i].X - steps1[i].X;
                    int deltaY = steps2[i].Y - steps1[i].Y;
                    lenghts[i] = Math.Sqrt(deltaX * deltaX + deltaY * deltaY);
                    lenghts[i] -= (lenghts[i] / 100 * 61);
                }

                double totalLenght = 0;

                for (int i = 0; i < N; i++)
                {
                    totalLenght += lenghts[i];
                }

                for (int i = 0; i < N; i++)
                {
                    double percent = (lenghts[i] / totalLenght) * 100;
                    double currentMs = ms * (percent / 100);
                    times[i] = Convert.ToInt32(currentMs);
                }

                //MessageBox.Show(Convert.ToString(times));
            }
        }

        public static double CalculateAngle(Point A, Point B)
        {
            return Angulo(A.X, A.Y, B.X, B.Y);
        }

        public static void mouse(int x, int y)
        {
            Point p;
            if (GetCursorPos(out p))
            {
                mouse_event((int)0x00000001, x, y, 0, 0);
            }
        }

        public static void AngleMouse(double angle, int speed)
        {
            double rad_angle = angle * Math.PI / 180;
            double x = speed * Math.Cos(rad_angle);
            double y = speed * Math.Sin(rad_angle);
            Point p;
            if (GetCursorPos(out p))
            {
                mouse_event((int)0x00000001, Convert.ToInt32(x), Convert.ToInt32(y), 1360, 1360);
            }
        }

        UserActivityHook actHook;
        private void Form1_Load(object sender, EventArgs e)
        {
            actHook = new UserActivityHook();
            actHook.OnMouseActivity += new MouseEventHandler(MouseMoved);
            actHook.KeyDown += new KeyEventHandler(MyKeyDown);
            actHook.KeyPress += new KeyPressEventHandler(MyKeyPress);
            actHook.KeyUp += new KeyEventHandler(MyKeyUp);
            actHook.Start();
        }

        public void MouseMoved(object sender, MouseEventArgs e)
        {
            if (switcher)
            {
                if (e.Clicks > 0)
                {
                    if (e.Button.ToString() == "Left")
                    {
                        RecoilStepTimer.Start();
                    }
                    if (e.Button.ToString() == "XButton1")
                    {
                        RecoilStepTimer.Stop();
                        i = 0;
                        ms_speeder = 0;
                        angle = Convert.ToInt32(RecoilInterface.angles[0]);
                        for (int i = 0; i < RecoilInterface.N; i++)
                        {
                            textBox.AppendText(Convert.ToString(RecoilInterface.lenghts[i]) + "\n");
                        }
                    }
                }
            }
        }

        public void MyKeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Insert)
            {
                switcher = true;
                SystemSounds.Exclamation.Play();
            }
            else if (e.KeyCode == Keys.Home)
            {
                switcher = false;
                SystemSounds.Hand.Play();
            }
            else if (e.KeyCode == Keys.F1)
            {
                RecoilInterface.Weapon_R99();
                ms_speeder = 0;
                angle = Convert.ToInt32(RecoilInterface.angles[0]);
                speedModifier = RecoilInterface.speed;
            }
            else if (e.KeyCode == Keys.F2)
            {
                MessageBox.Show(Convert.ToString(Angulo(0, 52, -8, 54)));
            }
        }

        public void MyKeyPress(object sender, KeyPressEventArgs e)
        {
            
        }

        public void MyKeyUp(object sender, KeyEventArgs e)
        {
            
        }

        private void RecoilStepTimer_Tick(object sender, EventArgs e)
        {
            AngleMouse(angle, speedModifier);
            if (ms_speeder >= RecoilInterface.times[i])
            {
                ms_speeder = 0;
                i++;
                if (i > RecoilInterface.N - 1)
                {
                    i = 0;
                }
                angle = Convert.ToInt32(RecoilInterface.angles[i]);
            }
            ms_speeder += 10;
        }

        static public double Angulo(int x1, int y1, int x2, int y2)
        {
            double degrees;
            if (x2 - x1 == 0)
            {
                if (y2 > y1)
                    degrees = 90;
                else
                    degrees = 270;
            }
            else
            {
                double riseoverrun = (double)(y2 - y1) / (double)(x2 - x1);
                double radians = Math.Atan(riseoverrun);
                degrees = radians * ((double)180 / Math.PI);
                if ((x2 - x1) < 0 || (y2 - y1) < 0)
                    degrees += 180;
                if ((x2 - x1) > 0 && (y2 - y1) < 0)
                    degrees -= 180;
                if (degrees < 0)
                    degrees += 360;
            }
            return degrees;
        }
    }
}
