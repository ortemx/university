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
        double x, y, eps, a, sum, F;
        int n;

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        string s1, s2;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            eps = 0.001;
            for (x = 0.1; x <= 1; x += 0.05)
            {
                a = x;
                sum = 0;
                n = 0;
                do
                {
                    sum += a;
                    y = (Math.Pow(x, 2)) / ((2 * n + 2) * (2 * n + 3));
                    a *= y;
                    n=n+1;
                } while (Math.Abs(a) >= eps);
                F = (Math.Exp(x) - Math.Exp(-x)) / 2;
                s1 = x.ToString() + "     "; s1 = s1.Substring(0, 6);
                s2 = sum.ToString() + "     "; s2 = s2.Substring(0, 6);
                listBox1.Items.Add(s1 = "\t" + " " + s2 + " " + "\t" + F);
            }
        }
    }
}
