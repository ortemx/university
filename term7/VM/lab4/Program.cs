using System;

class Program
{
    static double Function(double x)
    {
        return Math.Pow(x, 3) - 1 + 2 * x;
    }

    static double Derivative(double x)
    {
        return 3 * Math.Pow(x, 2) + 2;
    }

    static (double, int) NewtonRaphson(double x0, double epsilon)
    {
        double x1 = x0 - Function(x0) / Derivative(x0);
        int iterations = 1;
        while (Math.Abs(x1 - x0) > epsilon)
        {
            x0 = x1;
            x1 = x0 - Function(x0) / Derivative(x0);            
            iterations++;
        }

        return (x1, iterations);
    }

    static void Main(string[] args)
    {
        double initialGuess1 = 1.0; // First initial guess
        double initialGuess2 = 5.0; // Second initial guess
        double epsilon = 0.0001; // Desired accuracy

        // Solve using first initial guess
        var(root1, iter_num1) = NewtonRaphson(initialGuess1, epsilon);
        Console.WriteLine($"initialGuess: {initialGuess1} root: {root1} iterations: {iter_num1}");

        // Solve using second initial guess
        var(root2, iter_num2) = NewtonRaphson(initialGuess2, epsilon);
        Console.WriteLine($"initialGuess: {initialGuess2} root: {root2} iterations: {iter_num2}");
    }
}
