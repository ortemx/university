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
        double x, y, eps, a, sum, F, aa, bb;
        int n;
        string s1, s2;
        public string oldWxStr;

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

        private void textBox1_Enter(object sender, EventArgs e)
        {
            oldWxStr = textBox1.Text;

        }

        private void textBox2_Enter(object sender, EventArgs e)
        {
            oldWxStr = textBox2.Text;
        }
        private void textBox3_Enter(object sender, EventArgs e)
        {
            oldWxStr = textBox3.Text;
        }
        private void textBox1_Leave(object sender, EventArgs e)
        {
            try
            {
                //Какие - либо действия...
                aa = Convert.ToDouble(textBox1.Text);
            }
            catch (Exception ee)
            {
                //Возникла исключительная ситуация...
                MessageBox.Show("Недопустимое числовое значение...");
                textBox1.Text = oldWxStr;

                textBox1.Focus();
            }
            finally
            {
                //Завершающие действия обработчика...
            }
        }
        private void textBox2_Leave(object sender, EventArgs e)
        {
            try
            {
                //Какие - либо действия...
                bb = Convert.ToDouble(textBox2.Text);
            }
            catch (Exception ee)
            {
                //Возникла исключительная ситуация...
                MessageBox.Show("Недопустимое числовое значение...");
                textBox2.Text = oldWxStr;

                textBox1.Focus();
            }
            finally
            {
                //Завершающие действия обработчика...
            }
        }
        private void textBox3_Leave(object sender, EventArgs e)
        {
            try
            {
                //Какие - либо действия...
                eps = Convert.ToDouble(textBox3.Text);
            }
            catch (Exception ee)
            {
                //Возникла исключительная ситуация...
                MessageBox.Show("Недопустимое числовое значение...");
                textBox3.Text = oldWxStr;

                textBox1.Focus();
            }
            finally
            {
                //Завершающие действия обработчика...
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            aa = Convert.ToDouble(textBox1.Text);
            bb = Convert.ToDouble(textBox2.Text);
            eps = Convert.ToDouble(textBox2.Text);
            eps = 0.001;
            listBox1.Items.Clear();
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
                listBox1.Items.Add(s1  + "\t" + " " + s2 + " " + "\t" + F);
            }
        }
    }
}
