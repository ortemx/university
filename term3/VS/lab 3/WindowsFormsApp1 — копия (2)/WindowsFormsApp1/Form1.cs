using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private double x1, y1, x2, y2;
        private double x, y, xx, yy, t, h;
        private int I1, J1, I2, J2, n;

        private void textBox3_Leave(object sender, EventArgs e)
        {
            try
            {
                W1 = Convert.ToDouble(textBox3.Text);
            }
            catch (Exception ee)
            {
                MessageBox.Show("Недопустимое числовое значение...");
                textBox3.Text = oldWxStr;
                textBox3.Focus();
            }
            finally
            {
            }
            DrawGraphic();
        }

        private void textBox4_Leave(object sender, EventArgs e)
        {
            try
            {
                W2 = Convert.ToDouble(textBox4.Text);
            }
            catch (Exception ee)
            {
                MessageBox.Show("Недопустимое числовое значение...");
                textBox4.Text = oldWxStr;
                textBox4.Focus();
            }
            finally
            {
            }
            DrawGraphic();
        }

        private void textBox2_Leave(object sender, EventArgs e)
        {
            try
            {
                Wy = Convert.ToDouble(textBox2.Text);
            }
            catch (Exception ee)
            {
                MessageBox.Show("Недопустимое числовое значение...");
                textBox2.Text = oldWxStr;
                textBox2.Focus();
            }
            finally
            {
            }
            DrawGraphic();
        }

        private void textBox1_Leave(object sender, EventArgs e)
        {
            try
            {
                Wx = Convert.ToDouble(textBox1.Text);
            }
            catch (Exception ee)
            {
                MessageBox.Show("Недопустимое числовое значение...");
                textBox1.Text = oldWxStr;
                textBox1.Focus();
            }
            finally
            {
            }
            DrawGraphic();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DrawGraphic();
        }

        private double Wx, Wy, W1, W2;
        public string oldWxStr;

        public Form1()
        {
            InitializeComponent();
            n = 200;
            x1 = -1.2;
            x2 = 1.2;
            y1 = 1.2;
            y2 = -1.2;

            Wx = 2.3; Wy = 3.4; W1 = 6.2; W2 = 3.1;
            textBox1.Text = "2,3";
            textBox2.Text = "3,4";
            textBox3.Text = "6,2";
            textBox4.Text = "3,1";

            I1 = 3;
            J1 = 3;
            I2 = pictureBox1.Width - 3;
            J2 = pictureBox1.Height - 3;
            h = (x2 - x1) / n;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private int x_screen(double x)
        {
            return I1 + (int)((x - x1) * (I2 - I1) / (x2 - x1));
        }

        private int y_screen(double y)
        {
            return J1 - (int)((y - y1) * (J2 - J1) / (y1 - y2));
        }

        private double Fx(double t)
        {
            return Math.Sin(Wx * t + W1);
        }

        private double Fy(double t)
        {
            return Math.Sin(Wy * t + W2);
        }

        private void DrawGraphic()
        {
            var graphics = pictureBox1.CreateGraphics();
            graphics.FillRectangle(Brushes.Black, 0, 0, pictureBox1.Width - 1, pictureBox1.Height - 1);
            graphics.FillRectangle(Brushes.MintCream, 1, 1, pictureBox1.Width - 3, pictureBox1.Height - 3);
            t = 0;
            x = Fx(t); y = Fy(t);
            var pen = new Pen(Color.Red, 1.5F);
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Solid;
            for (int i = 1; i < 10 * n; i++)
            {
                t += h;
                xx = Fx(t); yy = Fy(t);
                graphics.DrawLine(pen, x_screen(x), y_screen(y), x_screen(xx), y_screen(yy));
                x = xx; y = yy;
            }
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dot;
            pen.Color = Color.Chocolate; pen.Width = 2.0F;
            graphics.DrawLine(pen, x_screen(0), y_screen(y1), x_screen(0), y_screen(y2));
            graphics.DrawLine(pen, x_screen(x1), y_screen(0), x_screen(x2), y_screen(0));
            graphics.DrawString("0", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(0) + 3, y_screen(0) - 15);
            graphics.DrawString("Y", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(0) - 15, y_screen(y1) + 3);
            graphics.DrawString("X", SystemFonts.DefaultFont, new SolidBrush(Color.Black), x_screen(x2) - 10, y_screen(0) - 15);

        }
    }
}
