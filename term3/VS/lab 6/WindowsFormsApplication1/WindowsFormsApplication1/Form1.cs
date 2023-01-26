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
using System.IO;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        string FileName = "images.bmp";
        Graphics g1, g2;
        Bitmap Bit1;
        Bitmap Bit2;
        Point[] u = new Point[4];
        Pen Pen1 = new Pen(Brushes.Black, 1);
        int NumPoint = -1;
        double A1, B1, C1, D1, A2, B2, C2, D2;
        double t1, t2;
        int I2, J2, x, y, i, j;
       

        public bool down = false;

        public Form1()
        {
            FileName = "images.bmp";
            u = new Point[4];
            Pen1 = new Pen(Brushes.Black, 1);
            NumPoint = -1;
            components = null;
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            g1 = pictureBox1.CreateGraphics();
            g2 = pictureBox2.CreateGraphics();

            button1.Enabled = false;
            button2.Enabled = false;
        }

        private void pictureBox2_MouseDown(object sender, MouseEventArgs e)
        {
            //Здесь код для управления нажатием левой кнопки мыши
            NumPoint = -1; //опорная точка четырехугольника не определена
            if (button1.Enabled)
            {
                x = e.X;  //координата х курсора мыши
                y = e.Y;  //координата y курсора мыши
                          //
                for (int i = 0; i < 4; i++)
                {
                    if ((((x >= (u[i].X - 20)) && (x <= (u[i].X + 20))) && (y >= (u[i].Y - 20))) && (y <= (u[i].Y + 20)))
                    {
                        NumPoint = i;
                        break;
                    }
                }
            }
        }

        private void pictureBox2_MouseUp(object sender, MouseEventArgs e)
        {
            // Здесь код для управления отпусканием левой кнопки мыши
            if (NumPoint != -1)
            {
                NumPoint = -1; button2_Click(sender, e);
            }
        }

        private void pictureBox2_MouseMove(object sender, MouseEventArgs e)
        {
            //Здесь код для управления перемещением мыши
            if (NumPoint == -1) { return; }
            x = e.X;  //координата х курсора мыши
            y = e.Y;  //координата y курсора мыши
            //
            if (((x >= 2) && !((x > (pictureBox2.Width - 2)) | (y < 2))) && (y <= (pictureBox2.Height - 2)))
            {
                u[NumPoint].X = x;
                u[NumPoint].Y = y;
                g2.Clear(Color.LightSteelBlue);
                Pen1.DashStyle = DashStyle.Solid;
                Pen1.Width = 2;
                Pen1.Color = Color.Red;
                g2.DrawRectangle(Pen1, 1, 1, pictureBox2.Width - 2, pictureBox2.Height - 2);
                Pen1.DashStyle = DashStyle.Dot;
                Pen1.Width = 2;
                Pen1.Color = Color.Black;
                g2.DrawPolygon(Pen1, u);
            }
        }       

        private void button3_Click(object sender, EventArgs e)
        {
            FileName = textBox1.Text; NewImage();
        }        

        private void button2_Click(object sender, EventArgs e)
        {            
            for (int i = 0; i < Bit2.Width; i++)
            {
                for (int j = 0; j < Bit2.Height; j++)
                {
                    Bit2.SetPixel(i, j, Color.LightSteelBlue);
                }
            }
            Pen1.DashStyle = DashStyle.Solid;
            Pen1.Width = 2;
            Pen1.Color = Color.Red;
            g2.DrawRectangle(Pen1, 1, 1, pictureBox2.Width - 2, pictureBox2.Height - 2);
            I2 = Bit1.Width;
            J2 = Bit1.Height;
            D1 = u[0].X;
            D2 = u[0].Y;
            A1 = ((double)(u[1].X - u[0].X)) / ((double)I2);
            A2 = ((double)(u[1].Y - u[0].Y)) / ((double)I2);
            C1 = ((double)(u[3].X - u[0].X)) / ((double)J2);
            C2 = ((double)(u[3].Y - u[0].Y)) / ((double)J2);
            B1 = (((double)(((u[2].X - u[3].X) - u[1].X) + u[0].X)) / ((double)I2)) / ((double)J2);
            B2 = (((double)(((u[2].Y - u[3].Y) - u[1].Y) + u[0].Y)) / ((double)I2)) / ((double)J2);
            for (int k = 0; k < I2; k++)
            {
                for (int m = 0; m < J2; m++)
                {
                    t1 = (((A1 * k) + ((B1 * k) * m)) + (C1 * m)) + D1;
                    t2 = (((A2 * k) + ((B2 * k) * m)) + (C2 * m)) + D2;
                    i = Convert.ToInt32(t1);
                    j = Convert.ToInt32(t2);
                    Bit2.SetPixel(i, j, Bit1.GetPixel(k, m));
                }
            }

            g2.DrawImage(Bit2, 0, 0);
            Pen1.DashStyle = DashStyle.Solid;
            Pen1.Width = 2;
            Pen1.Color = Color.Red;
            g2.DrawRectangle(Pen1, 1, 1, pictureBox2.Width - 2, pictureBox2.Height - 2);
            Pen1.DashStyle = DashStyle.Dot;
            Pen1.Width = 2;
            Pen1.Color = Color.Black;
            g2.DrawPolygon(Pen1, u);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            button2.Enabled = true;
            g1.Clear(Color.RosyBrown);
            g2.Clear(Color.LightSteelBlue);
            g1.DrawImage(Bit1, 0, 0);
            Pen1.DashStyle = DashStyle.Solid;
            Pen1.Width = 2;
            Pen1.Color = Color.Red;
            g1.DrawRectangle(Pen1, 1, 1, pictureBox1.Width - 2,pictureBox1.Height - 2);
            g2.DrawRectangle(Pen1, 1, 1, pictureBox2.Width - 2,pictureBox2.Height - 2);
            Pen1.DashStyle = DashStyle.Dot;
            Pen1.Width = 2;
            Pen1.Color = Color.Black;
            g2.DrawPolygon(Pen1, u);
        }

        private void NewImage()
        {
            if (File.Exists(textBox1.Text))
            {
                Bit1 = new Bitmap(FileName);
                Bit2 = new Bitmap(FileName);

                pictureBox1.Width = Bit1.Width;
                pictureBox2.Width = Bit2.Width;
                pictureBox1.Height = Bit1.Height;
                pictureBox2.Height = Bit2.Height;

                u[0].X = 10; u[0].Y = 10;
                u[1].X = Bit1.Width - 40; u[1].Y = 10;
                u[2].X = Bit1.Width - 10; u[2].Y = Bit1.Height - 10;
                u[3].X = 10; u[3].Y = Bit1.Height - 10;

                button1.Enabled = true;
                button2.Enabled = false;
            }
            else
            {
                pictureBox1.Width = 600;
                pictureBox2.Width = 600;
                pictureBox1.Height = 600;
                pictureBox2.Height = 600;
                button1.Enabled = false;
                button2.Enabled = false;
            }

            if (textBox1.Left + textBox1.Width > pictureBox1.Left + pictureBox1.Width + pictureBox2.Width)
            {
                Width = textBox1.Left + textBox1.Width + button3.Width + 25;
            }
            else
            {
                Width = pictureBox1.Left + pictureBox1.Width + pictureBox2.Width + 25;
            }

            Height = pictureBox1.Top + pictureBox1.Height +  button1.Height + 68;
            button1.Top = pictureBox1.Top + pictureBox1.Height + 5;
            button2.Top = button1.Top;
            textBox1.Top = button1.Top + 4;
            button3.Top = button1.Top;

            pictureBox2.Left = pictureBox1.Left + pictureBox1.Width + 5;
            pictureBox1.Refresh();
            pictureBox2.Refresh();
            g1.Clear(Color.RosyBrown);
            g2.Clear(Color.LightSteelBlue);

            Pen1.DashStyle = DashStyle.Solid;
            Pen1.Width = 2;
            Pen1.Color = Color.Red;
            g1.DrawRectangle(Pen1, 1, 1, pictureBox1.Width - 2, pictureBox1.Height - 2);
            g2.DrawRectangle(Pen1, 1, 1, pictureBox2.Width - 2, pictureBox2.Height - 2);
        }
    }
}
