using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private double x, y, h, x1, y1, x2, y2, temp1, temp2, temp3, temp_min, temp_max, y_min, y_max;
        private float xScreen, yScreen;
        private int I1, J1, I2, J2, xx1, xx2, yy1, yy2;
        Graphics graphics;
        Pen pen = new Pen(Color.Silver, 1);

        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            base.Capture = false;
            Message m = Message.Create(base.Handle, 0xa1, new IntPtr(2), IntPtr.Zero);
            this.WndProc(ref m);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DrawGraphic();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DrawGraphic2();
        }

        public Form1()
        {
            InitializeComponent();
            this.FormBorderStyle = FormBorderStyle.None;
            this.MouseDown += new MouseEventHandler(Form1_MouseDown);
            graphics = pictureBox1.CreateGraphics();
            x1 = -2.8;
            x2 = 3.1;
            I1 = 0;
            J1 = 0;
            I2 = pictureBox1.Width - 3;
            J2 = pictureBox1.Height - 3;
            h = 0.05;

        }
        private int x_screen(double x)
        {
            return I1 + (int)((x - x1) * (I2 - I1) / (x2 - x1));
        }
        private int y_screen(double y)
        {
            return J1 - (int)((y - y1) * (J2 - J1) / (y1 - y2));
        }

        private double F1(double x)
        {
            return 1.2 * Math.Sin(x * x) * Math.Exp(x / 5);
        }

        private double F2(double x)
        {
            return 1.2 * Math.Sin(x * x);
        }

        private double F3(double x)
        {
            return 2.25 * Math.Sin(x * x) * Math.Exp(x / 3);
        }

        private double F4(double x)
        {
            return Math.Abs(Math.Sin(x)) - Math.Abs(Math.Cos(x));
        }

        private void MinAndMax()
        {
            x = x1;
            while (x < x2)
            {
                temp1 = F1(x);
                temp2 = F2(x);
                temp3 = F3(x);

                if (temp1 > temp2)
                {
                    temp_max = temp1;
                    temp_min = temp2;
                }
                else
                {
                    temp_max = temp2;
                    temp_min = temp1;
                }

                if (temp3 < temp_min)
                {
                    temp_min = temp3;
                }
                if (temp3 > temp_max)
                {
                    temp_max = temp3;
                }

                if (temp_min < y2)
                {
                    y2 = temp_min;
                }
                if (temp_max > y1)
                {
                    y1 = temp_max;
                }
                x += h;
            }
        }

        private void DrawGrid()
        {
            pen.Color = Color.Black;
            for (int i = xx1; i <= xx2; i++) //цикл рисовки осей у
            {
                graphics.DrawLine(pen, x_screen(i), y_screen(y1), x_screen(i), y_screen(y2));
            }
            for (int i = yy2; i <= yy1; i++) //цикл рисовки осей х
            {
                graphics.DrawLine(pen, x_screen(x1), y_screen(i), x_screen(x2), y_screen(i));
            }
        }

        private void DrawAxis()
        {
            pen.Color = Color.Chocolate;
            graphics.DrawLine(pen, x_screen(0), y_screen(y1), x_screen(0), y_screen(y2));
            graphics.DrawLine(pen, x_screen(x1), y_screen(0), x_screen(x2), y_screen(0));
            graphics.DrawString("0", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(0) + 3, y_screen(0) - 15);
            graphics.DrawString("Y", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(0) - 15, y_screen(y1) + 3);
            graphics.DrawString("X", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(x2) - 10, y_screen(0) + 5);
        }

        public delegate double Func(double x);

        private void DrawFunc(Color color, Func F, double x)
        {
            pen.Color = color;
            x = x1;
            y = F(x);
            xScreen = x_screen(x);
            yScreen = y_screen(y);
            while (x < x2)
            {
                y = F(x);
                x += h;
                graphics.DrawLine(pen, xScreen, yScreen, x_screen(x), y_screen(y));
                xScreen = x_screen(x);
                yScreen = y_screen(y);
            }            
        }

        private void DrawGraphic()
        {           
            graphics.Clear(pictureBox1.BackColor);

            MinAndMax();

            xx1 = (int)Math.Floor(x1);
            xx2 = (int)Math.Floor(x2);
            yy1 = (int)Math.Floor(y1);
            yy2 = (int)Math.Floor(y2);

            DrawGrid();
            DrawAxis();

            DrawFunc(Color.Silver,  F1, x);
            DrawFunc(Color.Blue,    F2, x);
            DrawFunc(Color.Lime,    F3, x);
            
        }

        private void DrawGraphic2()
        {
            graphics.Clear(pictureBox1.BackColor);

            x = x1;
            y_min = F4(x);
            y_max = F4(x);
            while (x < x2)
            {
                y = F4(x);
                if (y < y_min)
                {
                    y_min = y;
                }
                if (y > y_max)
                {
                    y_max = y;
                }
                x += h;
            }
            y1 = y_max;
            y2 = y_min;

            DrawGrid();

            DrawFunc(Color.YellowGreen, F4, x);            

            DrawAxis();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
