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
        const int ncount = 5;
        Random rand = new Random();
        Point[] mypoints = new Point[ncount];
        int x_koord;
        int y_koord;
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
        private void button1_Click(object sender, EventArgs e)
        {
            DrawGraphic();
        }
        private void DrawGraphic()
        {
            var graphics = pictureBox1.CreateGraphics();
            graphics.FillRectangle(Brushes.Black, 0, 0, pictureBox1.Width - 1, pictureBox1.Height - 1);
            graphics.FillRectangle(Brushes.MintCream, 1, 1, pictureBox1.Width - 3, pictureBox1.Height - 3);
            var pen = new Pen(Color.Black, 2);
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dot;
            listBox1.Items.Clear();
            for (int i = 0; i < ncount; i++) // заполняет координаты точек и рисует их
            {
                x_koord = rand.Next(pictureBox1.Width - 50) + 40;
                y_koord = rand.Next(pictureBox1.Height - 50) + 40;
                mypoints[i].X = x_koord;
                mypoints[i].Y = y_koord;
                Rectangle r1 = new Rectangle(mypoints[i].X - 5, mypoints[i].Y - 5, 10, 10);
                listBox1.Items.Add((mypoints[i].X) + "\t" + " " + (mypoints[i].Y) + " " + "\t");
                graphics.FillEllipse(Brushes.Black, r1);
            }
            double min_p = Math.Sqrt(Math.Pow((mypoints[1].X - mypoints[0].X), 2) + Math.Pow(mypoints[1].Y - mypoints[0].Y, 2));
            double p;
            int x1_min = 0, y1_min = 0, x2_min = 0, y2_min = 0;
            for (int i = 0; i < ncount; i++) // соединяет все точки 
            {
                for (int j = 0; j < i; j++)
                {
                    graphics.DrawLine(pen, mypoints[i].X, mypoints[i].Y, mypoints[j].X, mypoints[j].Y);
                    p = Math.Sqrt(Math.Pow((mypoints[j].X - mypoints[i].X), 2) + Math.Pow(mypoints[j].Y - mypoints[i].Y, 2));
                    if (min_p >= p)
                    {
                        min_p = p;
                        x1_min = mypoints[i].X; y1_min = mypoints[i].Y; x2_min = mypoints[j].X; y2_min = mypoints[j].Y;
                    }
                }
            } 
            pen.Color = Color.Red;
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Solid;
            graphics.DrawLine(pen, x1_min, y1_min, x2_min, y2_min);
            Rectangle r2 = new Rectangle(x1_min - 5, y1_min - 5, 10, 10);
            graphics.FillEllipse(Brushes.Red, r2);
            Rectangle r3 = new Rectangle(x2_min - 5, y2_min - 5, 10, 10);
            graphics.FillEllipse(Brushes.Red, r3);
        }
    }
}
