using System;
using System.Collections.Generic;

class Program
{
    static double f(double x, double y) => x * x + 3 * y;
    static double g(double x) => 56f / 27 * Math.Exp(3 * x) - 1f / 3 * x * x - 2f / 9 * x - 2f / 27;

    static List<double> SolveEulerSymmetric(Func<double, double, double> f, double x0, double y0, double h, int n)
    {
        List<double> result = new List<double>
        {
            y0
        };

        double x = x0;
        double y = y0;

        for (int i = 0; i < n; i++)
        {
            double xHalf = x + h / 2;
            double yHalf = y + h / 2 * f(x, y);

            x += h;
            y += h * f(xHalf, yHalf);

            result.Add(y);
        }

        return result;
    }

    static void Main(string[] args)
    {
        double x0 = 0;
        double y0 = 2;
        double h1 = 0.1;
        double h2 = 0.01;
        int n1 = (int)((2 - x0) / h1);
        int n2 = (int)((2 - x0) / h2);

        List<double> result1 = SolveEulerSymmetric(f, x0, y0, h1, n1);
        List<double> result2 = SolveEulerSymmetric(f, x0, y0, h2, n2);

        Console.WriteLine($"h = {h1}");
        for (int i = 0; i < result1.Count; i++)
        {
            Console.WriteLine($"x = {x0 + i * h1, 4:f2}, y = {result1[i],10:f6}, exact value = {g(x0 + i * h1),10:f6}");
        }

        Console.WriteLine($"h = {h2}");
        for (int i = 0; i < result2.Count; i++)
        {
            Console.WriteLine($"x = {x0 + i * h2, 4:f2}, y = {result2[i],10:f6}, exact value = {g(x0 + i * h2),10:f6}");
        }
    }
}
