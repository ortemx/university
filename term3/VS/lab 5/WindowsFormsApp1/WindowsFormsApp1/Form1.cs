using System;
using System.Drawing;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        const int ncount = 5;
        Graphics graphics;
        Random rand = new Random();
        Point[] mypoints = new Point[ncount];
        Pen pen = new Pen(Color.Black, 3);
        int x_koord;
        int y_koord;

        public Form1()
        {
            InitializeComponent();
            this.FormBorderStyle = FormBorderStyle.None;
            this.MouseDown += new MouseEventHandler(Form1_MouseDown);
            
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            graphics = pictureBox1.CreateGraphics();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DrawGraphic();
        }
        private void DrawGraphic()
        {
            graphics.Clear(pictureBox1.BackColor);
            pen.Color = Color.Black;
            pen.DashStyle = DashStyle.Dot;
            for (int i = 0; i < ncount; i++) // заполняет координаты точек и рисует их
            {
                x_koord = rand.Next(pictureBox1.Width - 50) + 40;
                y_koord = rand.Next(pictureBox1.Height - 50) + 40;
                mypoints[i].X = x_koord;
                mypoints[i].Y = y_koord;
                Rectangle r1 = new Rectangle(mypoints[i].X - 5, mypoints[i].Y - 5, 10, 10);
                graphics.FillEllipse(Brushes.Black, r1);
            }
            double min_p = Math.Pow((mypoints[1].X - mypoints[0].X), 2) + Math.Pow(mypoints[1].Y - mypoints[0].Y, 2);
            double p;
            int x1_min = 0, y1_min = 0, x2_min = 0, y2_min = 0;
            for (int i = 0; i < ncount; i++) // соединяет все точки 
            {
                for (int j = i+1; j < ncount; j++)
                {
                    graphics.DrawLine(pen, mypoints[i].X, mypoints[i].Y, mypoints[j].X, mypoints[j].Y);
                    p = Math.Pow((mypoints[j].X - mypoints[i].X), 2) + Math.Pow(mypoints[j].Y - mypoints[i].Y, 2);
                    if (min_p * min_p >= p * p)
                    {
                        min_p = p;
                        x1_min = mypoints[i].X;
                        y1_min = mypoints[i].Y;
                        x2_min = mypoints[j].X;
                        y2_min = mypoints[j].Y;
                    }
                }
            } 
            pen.Color = Color.LawnGreen;
            pen.DashStyle = DashStyle.Solid;
            graphics.DrawLine(pen, x1_min, y1_min, x2_min, y2_min);
            Rectangle r2 = new Rectangle(x1_min - 5, y1_min - 5, 10, 10);
            graphics.FillEllipse(Brushes.LawnGreen, r2);
            Rectangle r3 = new Rectangle(x2_min - 5, y2_min - 5, 10, 10);
            graphics.FillEllipse(Brushes.LawnGreen, r3);
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
    }
}
