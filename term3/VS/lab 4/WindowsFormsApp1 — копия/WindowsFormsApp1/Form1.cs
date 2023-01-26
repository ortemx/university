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
        private double x, y, h;
        private int I1, J1, I2, J2, n;

        private void button1_Click(object sender, EventArgs e)
        {
            DrawGraphic();
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
            return 1.2 * Math.Sin(x * x);
        }

        private double FFF(double x)
        {
            return 2.25 * Math.Sin(x * x) * Math.Exp(x / 3);
        }

        private void DrawGraphic()
        {

            var graphics = pictureBox1.CreateGraphics();
            graphics.FillRectangle(Brushes.Black, 0, 0,

            pictureBox1.Width - 1, pictureBox1.Height - 1);
            graphics.FillRectangle(Brushes.MintCream, 1, 1,
            pictureBox1.Width - 3,
            pictureBox1.Height - 3);

            x = x1;
            var pen = new Pen(Color.Red, 1.5F);
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
