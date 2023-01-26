using System;
using System.Drawing;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private double x1, y1, x2, y2;
        private double x, y, xx, yy, t, h;
        private int I1, J1, I2, J2, n;
        private double Wx, Wy, W1, W2;
        public string oldWxStr;
        Graphics graphics;
        Pen pen = new Pen(Color.Silver, 1);

        private void textBox3_Leave(object sender, EventArgs e)
        {
            try
            {
                W1 = Convert.ToDouble(textBox3.Text);
            }
            catch 
            {
                MessageBox.Show("Недопустимое числовое значение...");
                textBox3.Text = oldWxStr;
                textBox3.Focus();
            }
            finally
            {
            }
        }

        private void textBox4_Leave(object sender, EventArgs e)
        {
            try
            {
                W2 = Convert.ToDouble(textBox4.Text);
            }
            catch
            {
                MessageBox.Show("Недопустимое числовое значение...");
                textBox4.Text = oldWxStr;
                textBox4.Focus();
            }
            finally
            {
            }
        }      

        private void textBox2_Leave(object sender, EventArgs e)
        {
            try
            {
                Wy = Convert.ToDouble(textBox2.Text);
            }
            catch
            {
                MessageBox.Show("Недопустимое числовое значение...");
                textBox2.Text = oldWxStr;
                textBox2.Focus();
            }
            finally
            {
            }
        }

        private void textBox1_Leave(object sender, EventArgs e)
        {
            try
            {
                Wx = Convert.ToDouble(textBox1.Text);
            }
            catch 
            {
                MessageBox.Show("Недопустимое числовое значение...");
                textBox1.Text = oldWxStr;
                textBox1.Focus();
            }
            finally
            {
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DrawGraphic();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            base.Capture = false;
            Message m = Message.Create(base.Handle, 0xa1, new IntPtr(2), IntPtr.Zero);
            this.WndProc(ref m);
        }


        public Form1()
        {
            InitializeComponent();
            graphics = pictureBox1.CreateGraphics();
            this.FormBorderStyle = FormBorderStyle.None;
            this.MouseDown += new MouseEventHandler(Form1_MouseDown);
            n = 200;
            x1 = -1.2;
            x2 = 1.2;
            y1 = 1.2;
            y2 = -1.2;
            
            textBox1.Text = "2,3"; Wx = 2.3;
            textBox2.Text = "3,4"; Wy = 3.4;
            textBox3.Text = "6,2"; W1 = 6.2;
            textBox4.Text = "3,1"; W2 = 3.1;

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

        private void DrawAxis()
        {
            pen.DashStyle = DashStyle.Dot;
            pen.Color = Color.Chocolate;
            pen.Width = 2;
            graphics.DrawLine(pen, x_screen(0), y_screen(y1), x_screen(0), y_screen(y2)); //рисует ось у
            graphics.DrawLine(pen, x_screen(x1), y_screen(0), x_screen(x2), y_screen(0)); //рисует ось х
            graphics.DrawString("0", SystemFonts.DefaultFont, new SolidBrush(Color.Silver), x_screen(0) + 3, y_screen(0) - 15);
            graphics.DrawString("Y", SystemFonts.DefaultFont, new SolidBrush(Color.Silver), x_screen(0) - 15, y_screen(y1) + 3);
            graphics.DrawString("X", SystemFonts.DefaultFont, new SolidBrush(Color.Silver), x_screen(x2) - 10, y_screen(0) + 5);
        }
        private void DrawGraphic()
        {
            graphics.Clear(pictureBox1.BackColor);
            
            t = 0;
            x = Fx(t);
            y = Fy(t);
            pen.Color = Color.Silver;
            pen.Width = 1;
            pen.DashStyle = DashStyle.Solid;
            for (int i = 1; i < 10 * n; i++)
            {
                t += h;
                xx = Fx(t);
                yy = Fy(t);
                graphics.DrawLine(pen, x_screen(x), y_screen(y), x_screen(xx), y_screen(yy)); //рисует график функции
                x = xx;
                y = yy;
            }

            DrawAxis();
        }
    }
}
