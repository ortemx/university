namespace BisectionMethod
{
    using System;

    class Program
    {
        static double Function(double x)
        {
            return (x * x) - 16;
        }

        static void Main()
        {
            double a = -5.0;
            double b = 5.0;
            double eps = 0.0001;
            int i = 1;
            double d = b - a;
            double m;
            for (; ; i++)
            {
                d = d / 2;
                m = a + d;
                if (Math.Abs(Function(m)) < eps)
                {
                    break;
                }
                if (Math.Sign(Function(a)) == Math.Sign(Function(m)))
                {
                    a = m;
                }
            }

            Console.WriteLine("Корень уравнения равен " + m);
            Console.WriteLine("Количество итераций равно " + i);
        }
    }
}
