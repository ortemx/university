using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public List<Point> points = new List<Point>();
        Graphics graphics;
        int split_;

        public Form1()
        {
            InitializeComponent();

            pictureBox1.BackColor = Color.FromArgb(40, 40, 40);
            pictureBox2.BackColor = Color.FromArgb(70, 70, 70);
            split_ = trackBar1.Value;
            fillList();            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            drawPol();
            drawPoints(pictureBox1.CreateGraphics());
        }


        void drawPol()
        {
            graphics = pictureBox1.CreateGraphics();
            Pen pen = new Pen(Color.Red);
            for (int i = 0; i < points.Count() - 1; i++)
            {
                graphics.DrawLine(pen, points[i], points[i + 1]);
            }
            graphics.DrawLine(pen, points.Last(), points[0]);
        }


        PointF B(List<Point> points, int i, float t)
        {
            Point A, B, C, D;
            int n = points.Count();
            if (i == 0)
            {
                A = points[n - 1];
                B = points[i];
                C = points[i + 1];
                D = points[i + 2];
            }
            else if (i == n - 2)
            {
                A = points[i - 1];
                B = points[i];
                C = points[i + 1];
                D = points[0];
            }
            else if (i == n - 1)
            {
                A = points[i - 1];
                B = points[i];
                C = points[0];
                D = points[1];
            }
            else
            {
                A = points[i - 1];
                B = points[i];
                C = points[i + 1];
                D = points[i + 2];
            }
            float x = (1 - t) * (1 - t) * (1 - t) * A.X + 3 * (1 - t) * (1 - t) * t * B.X + 3 * (1 - t) * t * t * C.X + t * t * t * D.X;
            float y = (1 - t) * (1 - t) * (1 - t) * A.Y + 3 * (1 - t) * (1 - t) * t * B.Y + 3 * (1 - t) * t * t * C.Y + t * t * t * D.Y;
            return new PointF(x, y);
        }

        void fillList()
        {
            string line;
            try
            {
                //Pass the file path and file name to the StreamReader constructor
                StreamReader sr = new StreamReader("prim1.krd");
                //Read the first line of text
                line = sr.ReadLine();
                //Continue to read until you reach end of file
                while (line != null)
                {
                    //write the line to console window
                    int x = Convert.ToInt32(line.Substring(0, line.IndexOf(" ")));
                    int y = Convert.ToInt32(line.Substring(line.IndexOf(" ") + 1));
                    points.Add(new Point(x, y));
                    //Read the next line
                    line = sr.ReadLine();
                    line = sr.ReadLine();
                }
                //close the file
                sr.Close();
            }
            catch (Exception ee)
            {
                Console.WriteLine("Exception: " + ee.Message);
            }
            finally
            {
                Console.WriteLine("Executing finally block.");
            }

        }

        void drawPoints(Graphics graphics)
        {
            for (int i = 0; i < points.Count; i++)
            {
                Rectangle r = new Rectangle(points[i].X - 2, points[i].Y - 2, 4, 4);
                graphics.FillEllipse(Brushes.Lime, r);
            }
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            split_ = trackBar1.Value;
            pictureBox2.CreateGraphics().Clear(Color.FromArgb(70, 70, 70));
            drawPoints(pictureBox2.CreateGraphics());
            listBox1.Items.Clear();
            listBox1.Items.Add("elements in points " + points.Count());
            int count = 0;
            for (int i = 1; i < points.Count(); i+=3)
            {
                PointF OldPoint = points[i - 1];
                for (float t = 0; t <= 1.1; t += 1f / split_)
                {
                    PointF P = B(points, i, t);
                    pictureBox2.CreateGraphics().DrawLine(new Pen(Color.FromArgb(84, 135, 235), 1), OldPoint, P);
                    OldPoint = P;
                    count++;
                }
            }
            listBox1.Items.Add("number of iterations" + count);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            drawPoints(pictureBox2.CreateGraphics());
            for (int i = 1; i < points.Count(); i+=3)
            {
                PointF OldPoint = points[i - 1];
                for (float t = 0; t <= 1.1; t += 1F / split_)
                {
                    PointF P = B(points, i, t);
                    pictureBox2.CreateGraphics().DrawLine(new Pen(Color.FromArgb(84, 135, 235), 1), OldPoint, P);
                    OldPoint = P;
                }
            }
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            graphics = pictureBox1.CreateGraphics();
            graphics.Clear(Color.FromArgb(40, 40, 40));
        }

        private void pictureBox2_MouseDown(object sender, MouseEventArgs e)
        {
            pictureBox2.CreateGraphics().Clear(Color.FromArgb(70, 70, 70));
        }
    }
}
