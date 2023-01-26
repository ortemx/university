using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private double x1, y1, x2, y2;
        private double x, y, h;
        private int I1, J1, I2, J2, n, xx1, xx2;

        private void button1_Click(object sender, EventArgs e)
        {
            DrawGraphic();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DrawGraphic2();
        }

        private double y_min, y_max;

        public Form1()
        {
            InitializeComponent();
            n = 200;
            x1 = -2.8;
            x2 = 3.1;
            I1 = 3;
            J1 = 3;
            I2 = pictureBox1.Width - 3;
            J2 = pictureBox1.Height - 3;
            h = (x2 - x1) / n;

        }
        private int x_screen(double x)
        {
            return I1 + (int)((x - x1) * (I2 - I1) / (x2 - x1));
        }
        private int y_screen(double y)
        {
            return J1 - (int)((y - y1) * (J2 - J1) / (y1 - y2));
        }
        private double F(double x)
        {
            return 1.2 * Math.Sin(x * x) * Math.Exp(x / 5);
        }

        private double FF(double x)
        {
            return 11.2 * Math.Sin(x * x);
        }

        private double FFF(double x)
        {
            return 2.25 * Math.Sin(x * x) * Math.Exp(x / 3);
        }

        private double F4(double x)
        {
            return Math.Abs(Math.Sin(x)) - Math.Abs(Math.Cos(x));
        }
        private void DrawGraphic()
        {
            var graphics = pictureBox1.CreateGraphics();
            graphics.FillRectangle(Brushes.Black, 0, 0, pictureBox1.Width - 1, pictureBox1.Height - 1);
            graphics.FillRectangle(Brushes.MintCream, 1, 1, pictureBox1.Width - 3, pictureBox1.Height - 3);
            x = x1;
            y_min = F(x);
            y_max = F(x);
            x += h;
            while (x < x2)
            {
                y = F(x);
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

            x = x1;
            while (x < x2)
            {
                y = FF(x);
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

            x = x1;
            while (x < x2)
            {
                y = FFF(x);
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

            xx1 = (int)Math.Floor(x1);
            xx2 = (int)Math.Floor(x2);

            var pen = new Pen(Color.Silver, 2);
            pen.Color = Color.Red;

            var xScreen = xx1;
            var yScreen = y_screen(y1);

            for (int i = xx1; i < xx2; i++)
            {
                graphics.DrawLine(pen, x_screen(i), y_screen(y1), x_screen(i), y_screen(y2));
            }

            pen = new Pen(Color.Silver, 2);


            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Solid;
            x = x1;
            y = F(x);

            while (x < x2)
            {
                y = F(x);
                x += h;
                graphics.DrawLine(pen, xScreen, yScreen, x_screen(x), y_screen(y));
                xScreen = x_screen(x);
                yScreen = y_screen(y);
            }

            pen.Color = Color.Blue;
            x = x1;
            y = FF(x);
            xScreen = x_screen(x);
            yScreen = y_screen(y);
            while (x < x2)
            {
                y = FF(x);
                x += h;
                graphics.DrawLine(pen, xScreen, yScreen, x_screen(x), y_screen(y));
                xScreen = x_screen(x);
                yScreen = y_screen(y);
            }

            pen.Color = Color.Lime;
            x = x1;
            y = FFF(x);
            xScreen = x_screen(x);
            yScreen = y_screen(y);
            while (x < x2)
            {
                y = FFF(x); x += h;
                graphics.DrawLine(pen, xScreen, yScreen, x_screen(x), y_screen(y));
                xScreen = x_screen(x);
                yScreen = y_screen(y);
            }

            pen.Color = Color.Chocolate; pen.Width = 2;
            graphics.DrawLine(pen, x_screen(0), y_screen(y1), x_screen(0), y_screen(y2));
            graphics.DrawLine(pen, x_screen(x1), y_screen(0), x_screen(x2), y_screen(0));
            graphics.DrawString("0", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(0) + 3, y_screen(0) - 15);
            graphics.DrawString("Y", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(0) - 15, y_screen(y1) + 3);
            graphics.DrawString("X", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(x2) - 10, y_screen(0) + 5);

            // x = Math.
        }

        private void DrawGraphic2()
        {
            var graphics = pictureBox1.CreateGraphics();
            graphics.FillRectangle(Brushes.Black, 0, 0, pictureBox1.Width - 1, pictureBox1.Height - 1);
            graphics.FillRectangle(Brushes.MintCream, 1, 1, pictureBox1.Width - 3, pictureBox1.Height - 3);
            x = x1;
            y_min = FFF(x);
            y_max = FFF(x);
            x += h;
            while (x < x2)
            {
                y = FFF(x);
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
            var pen = new Pen(Color.Silver, 2);

            pen.Color = Color.Black;
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Solid;
            x = x1;
            y = F4(x);
            var xScreen = x_screen(x);
            var yScreen = y_screen(y);
            while (x < x2)
            {
                y = F4(x);
                x += h;
                graphics.DrawLine(pen, xScreen, yScreen, x_screen(x), y_screen(y));
                xScreen = x_screen(x);
                yScreen = y_screen(y);
            }

            pen.Color = Color.Chocolate; pen.Width = 2;
            graphics.DrawLine(pen, x_screen(0), y_screen(y1), x_screen(0), y_screen(y2));
            graphics.DrawLine(pen, x_screen(x1), y_screen(0), x_screen(x2), y_screen(0));
            graphics.DrawString("0", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(0) + 3, y_screen(0) - 15);
            graphics.DrawString("Y", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(0) - 15, y_screen(y1) + 3);
            graphics.DrawString("X", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(x2) - 10, y_screen(0) + 5);
        }


        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}