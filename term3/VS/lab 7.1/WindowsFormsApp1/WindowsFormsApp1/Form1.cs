using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        Graphics g1, g2, g3, g4;
        Color c1, c2, c3, c4;

        public string[] file = File.ReadAllLines(@"123.txt");
        public StreamReader ReadFile = File.OpenText(@"123.txt");
        public string Input;
            

    public Form1()
        {
            
            this.FormBorderStyle = FormBorderStyle.None;
            this.MouseDown += new MouseEventHandler(Form1_MouseDown); 
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            g1.Clear(c2);
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            g1.Clear(c3);
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            g1.Clear(c4);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            g1 = pictureBox1.CreateGraphics();
            g2 = pictureBox2.CreateGraphics();
            g3 = pictureBox3.CreateGraphics();
            g4 = pictureBox4.CreateGraphics();
            
            g1.Clear(Color.LightBlue);
            g2.Clear(Color.LightSteelBlue);
            c2 = Color.LightSteelBlue;
            g3.Clear(Color.Red);
            c3 = Color.Red;
            g4.Clear(Color.Black);
            c4 = Color.Black;


            string s = "";
            string count = ReadFile.ReadLine();
            int n = Convert.ToInt32(count);
            Point[] mypoints = new Point[n];
            for (int j  = 0; j < n; j++)
            {
                s = ReadFile.ReadLine();
                mypoints[j].X = Convert.ToInt32(s.Substring(0, s.IndexOf(" ")));
                mypoints[j].Y = Convert.ToInt32(s.Substring(s.IndexOf(" ") + 1));
                listBox1.Items.Add(mypoints[j].X + " " + mypoints[j].Y);               
            }

            Pen Pen1 = new Pen(Brushes.Black, 1);
            Pen1.Width = 2;
            Pen1.Color = Color.Black;
            g1.DrawPolygon(Pen1, mypoints);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
            
        }

        private void pictureBox2_MouseDown(object sender, MouseEventArgs e)
        {

        }

        private void pictureBox3_MouseDown(object sender, MouseEventArgs e)
        {

        }

        private void pictureBox4_MouseDown(object sender, MouseEventArgs e)
        {

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
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
