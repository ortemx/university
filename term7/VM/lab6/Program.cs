using System;

class Program
{
    static double AitkenScheme(Func<double, double> function, double initialGuess, double epsilon, int maxIterations)
    {
        double x_n = initialGuess;
        double x_n_minus_1 = function(x_n);
        double x_n_minus_2 = function(x_n_minus_1);

        int iterations = 0;
        while (Math.Abs(x_n - x_n_minus_2) >= epsilon && iterations < maxIterations)
        {
            double x_n_plus_1 = function(x_n_minus_2);
            double x_n_plus_2 = x_n_minus_2 - Math.Pow(x_n_plus_1 - x_n_minus_2, 2) / (x_n - 2 * x_n_minus_1 + x_n_minus_2);

            x_n = x_n_plus_2;
            x_n_minus_1 = x_n_plus_1;
            x_n_minus_2 = x_n_plus_2;

            iterations++;
        }

        return x_n;
    }

    static void Main(string[] args)
    {
        // Пример использования схемы Эйткена для приближенного вычисления корня уравнения x^2 - 4 = 0
        Func<double, double> equation = x => Math.Pow(x, 2) - 4;
        double initialGuess = 1.43;
        double epsilon = 0.0001;
        int maxIterations = 100;

        double root = AitkenScheme(equation, initialGuess, epsilon, maxIterations);
        Console.WriteLine("Root: " + root);
    }
}