﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Drawing2D;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {        
        private double x1, y1, x2, y2;
        private int I1, J1, I2, J2, n;
        List <region> regions = new List <region> (0);
        int NumReg = -1;
        Point XYMin;
        Point XYMax;
        Point[] XYKontur;
        Point[] XYKonturWork;

        Graphics graphics;
        Pen pen = new Pen(Brushes.Black, 2);
        Pen pen2 = new Pen(Brushes.LightGray, 1);
        Brush b1 = Brushes.DarkGray;

        private void button1_Click(object sender, EventArgs e)
        {            
            string KontFile = "RAION0.KRD";
            using (StreamReader sr = new StreamReader(KontFile))
            {
                int n = Convert.ToInt32(sr.ReadLine());
                XYMin = new Point();
                XYMax = new Point();
                string s = sr.ReadLine();
                XYMin.X = Convert.ToInt32(s.Substring(s.IndexOf(" ") + 1));
                XYMax.X = Convert.ToInt32(s.Substring(0, s.IndexOf(" ")));
                this.x1 = XYMin.X;
                this.x2 = XYMax.X;
                s = sr.ReadLine();
                XYMin.Y = Convert.ToInt32(s.Substring(s.IndexOf(" ") + 1));
                XYMax.Y = Convert.ToInt32(s.Substring(0, s.IndexOf(" ")));
                this.y2 = XYMax.Y;
                this.y1 = XYMin.Y;
                sr.ReadLine();
                XYKontur = new Point[n];
                for (int i = 0; i < n; i++)
                {
                    s = sr.ReadLine();
                    XYKontur[i].X = Convert.ToInt32(s.Substring(0, s.IndexOf(" ")));
                    XYKontur[i].Y = Convert.ToInt32(s.Substring(s.IndexOf(" ") + 1));
                    XYKontur[i].X = x_screen(XYKontur[i].X);
                    XYKontur[i].Y = y_screen(XYKontur[i].Y);                    
                }

                pen.DashStyle = DashStyle.Solid;
                graphics = pictureBox1.CreateGraphics();
                pen.Color = genRandomColor2();
                graphics.DrawPolygon(pen, XYKontur);
                graphics.FillPolygon(b1, XYKontur);
            }
            KonturReg();
        }

        public void KonturReg()
        {
            int xx, yy, dd;
            for (int num = 1; num < 24; num++)
            {                
                string filename = "RAION" + num + ".KRD";
                if (File.Exists(filename))
                {
                    using (StreamReader sr = new StreamReader(filename, Encoding.GetEncoding("Windows-1251")))
                    {
                        regions.Add(new region());
                        string s = sr.ReadLine();
                        regions[num - 1].population = Convert.ToInt32(s.Substring(0, s.IndexOf(" ")));
                        var nfi = new System.Globalization.NumberFormatInfo();
                        nfi.NumberDecimalSeparator = ".";
                        regions[num - 1].area = Double.Parse(s.Substring(s.IndexOf(" ") + 1), nfi);
                        regions[num - 1].region_name = sr.ReadLine();
                        regions[num - 1].region_center = sr.ReadLine();
                        s = sr.ReadLine();
                        regions[num - 1].center_coords.X = Convert.ToInt32(s.Substring(0, s.IndexOf(" ")));
                        regions[num - 1].center_coords.Y = Convert.ToInt32(s.Substring(s.IndexOf(" ")));
                        regions[num - 1].center_coords.X = x_screen(regions[num - 1].center_coords.X);
                        regions[num - 1].center_coords.Y = y_screen(regions[num - 1].center_coords.Y);
                        regions[num - 1].XYKonturReg = new Point[Convert.ToInt32(sr.ReadLine())];
                        s = sr.ReadLine();
                        regions[num - 1].XYMin.X = Convert.ToInt32(s.Substring(s.IndexOf(" ") + 1));
                        regions[num - 1].XYMax.X = Convert.ToInt32(s.Substring(0, s.IndexOf(" ")));
                        s = sr.ReadLine();
                        regions[num - 1].XYMin.Y = Convert.ToInt32(s.Substring(s.IndexOf(" ") + 1));
                        regions[num - 1].XYMax.Y = Convert.ToInt32(s.Substring(0, s.IndexOf(" ")));
                        s = sr.ReadLine();

                        for (int i = 0; i < regions[num - 1].XYKonturReg.Length; i++)
                        {
                            s = sr.ReadLine();
                            regions[num - 1].XYKonturReg[i].X = Convert.ToInt32(s.Substring(0, s.IndexOf(" ")));
                            if (i != regions[num - 1].XYKonturReg.Length - 1)
                                regions[num - 1].XYKonturReg[i].Y = Convert.ToInt32(s.Substring(s.IndexOf(" ") + 1, s.Length - s.IndexOf(" ") - 1));
                            else
                            {
                                regions[num - 1].XYKonturReg[i].Y = Convert.ToInt32(s.Substring(s.IndexOf(" ") + 1, s.Length - s.IndexOf(" ") - 2));                                
                            }
                            //преобразование
                            regions[num - 1].XYKonturReg[i].X = x_screen(regions[num - 1].XYKonturReg[i].X);
                            regions[num - 1].XYKonturReg[i].Y = y_screen(regions[num - 1].XYKonturReg[i].Y); 
                        }
                    }
                }
                //отрисовка регионов       
                regions[num - 1].ColorReg = genRandomColor2();
                Brush b1 = new SolidBrush(regions[num - 1].ColorReg);
                graphics.FillPolygon(b1, regions[num - 1].XYKonturReg);
                pen.Color = Color.FromArgb(180, 180, 180 );
                graphics.DrawPolygon(pen, regions[num - 1].XYKonturReg);
            }

            for (int num = 1; num < 24; num++) //отрисовка столиц регионов
            {
                xx = regions[num - 1].center_coords.X;
                yy = regions[num - 1].center_coords.Y;
                dd = regions[num - 1].region_center.Length;

                Rectangle r1 = new Rectangle(xx - 4, yy - 4, 8, 8);
                graphics.DrawEllipse(pen2, r1);

                Rectangle r2 = new Rectangle(xx - 8 * dd / 2, yy - 20, 8*dd, 15);
                Brush b2 = new SolidBrush(Color.FromArgb(10, 10, 10));
                graphics.FillRectangle(b2, r2);
                graphics.DrawString(regions[num - 1].region_center, new Font ("Segoe UI", 10, FontStyle.Regular) , new SolidBrush(Color.Black), xx - 7 * dd / 2, yy - 22);
            }
        }

        Random MyRandom = new Random();

        public class region
        {
            public string region_name;
            public Double area;
            public int population;
            public string region_center;
            public Point center_coords;
            public Point[] XYKonturReg;
            public Point XYMin;
            public Point XYMax;
            public Color ColorReg;
        }        

        public Color genRandomColor()
        {
            int red = MyRandom.Next(156) + 100;
            int green = MyRandom.Next(156) + 100;
            int blue = MyRandom.Next(156) + 100;
            return Color.FromArgb(red, green, blue);
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (NumReg == -1) { return; }
            int x = e.X;  //координата х курсора мыши
            int y = e.Y;  //координата y курсора мыши
            //
            int xx;
            int yy;
            for (int i = 0; i < 23; i++)
            {
                xx = regions[i].center_coords.X;
                yy = regions[i].center_coords.Y;
                if ((((x >= (xx - 6)) && (x <= (xx + 6))) && (y >= (yy - 6))) && (y <= (yy + 6)))
                {
                    if  (i != NumReg)
                    {
                        NumReg = i;
                        listBox1.Items.Clear();
                        listBox1.Items.Add(regions[i].region_name);
                    }
                    return;
                }
            }
            NumReg = - 1;
        }

        public Color genRandomColor2()
        {
            int xxx = MyRandom.Next(150);         
            return Color.FromArgb(xxx, xxx, xxx);
        }

        private int x_screen(double x)
        {            
            return I1 + (int)((x - x1) * (I2 - I1) / (x2 - x1));
        }

        private int y_screen(double y)
        {
            return J1 - (int)((y - y1) * (J2 - J1) / (y1 - y2));
        }
        

        public Form1()
        {
            this.FormBorderStyle = FormBorderStyle.None;
            this.MouseDown += new MouseEventHandler(Form1_MouseDown);
            InitializeComponent();
            I1 = 0;
            J1 = 0;
            I2 = pictureBox1.Width - 3;
            J2 = pictureBox1.Height - 3;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            base.Capture = false;
            Message m = Message.Create(base.Handle, 0xa1, new IntPtr(2), IntPtr.Zero);
            this.WndProc(ref m);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }
    }
}
