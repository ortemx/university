using System;

class Program
{
    static double Function(double x)
    {
        return Math.Sin(1/(x*x));
    }

    static double MidpointRectangleRule(Func<double, double> function, double a, double b)
    {
        double midpoint = (a + b) / 2;
        double result = (b - a) * function(midpoint);
        return result;
    }

    static double TrapezoidalRule(Func<double, double> function, double a, double b, int n)
    {
        double h = (b - a) / n;
        double sum = (function(a) + function(b)) / 2;

        for (int i = 1; i < n; i++)
        {
            double x = a + i * h;
            sum += function(x);
        }

        return h * sum;
    }    

    static void Main(string[] args)
    {
        double a = 1;
        double b = 2;

        double integral = MidpointRectangleRule(Function, a, b);
        Console.WriteLine("Approximate integral: " + integral);
    }
}