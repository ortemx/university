using static System.Math;

class Program
{
    delegate double Functions(double x);

    static double MidpointRectangleRule(Functions function, double a, double b)
    {
        return (b - a) * function((a + b) / 2);
    }

    static double TrapezoidalRule(Functions function, double a, double b)
    {
        return (b - a) * ((function(a) + function(b)) / 2);
    }

    static double SimpsonRule(Functions function, double a, double b)
    {
        return (b - a) * (function(a) + 4 * function((a + b) / 2) + function(b)) / 6;
    }
    struct Limits
    {
        public double a;
        public double b;
    }

    static void Main()
    {
        List<Functions> functions = new()
        {
            (x) => Sin(1 / (x * x)),
            (x) => x * Sin(1 / (x * x * x)),
            (x) => Exp(x) * Cos(1 / (x * x * x)),
            (x) => Exp(x) / x * Cos(1 / (x * x * x)),
            (x) => Pow(2,x) * Log(x)
        };

        List<Limits> limits = new() {
            new Limits { a = 1, b = 2 },
            new Limits { a = 1, b = 2 },
            new Limits { a = 1, b = 2 },
            new Limits { a = 2, b = 4 },
            new Limits { a = 3, b = 4 },
        };

        List<double[]> values = new()
        {
            new double[] { 0, 0 },
            new double[] { 0, 0 },
            new double[] { 0, 0 },
        };

        int n = 1000;

        for (int i = 0; i < functions.Count; i++)
        {

            double h = (limits[i].b - limits[i].a) / n;

            for (double x = limits[i].a; x < limits[i].b; x += h)
            {
                values[0][0] += functions[i](x + h / 2);
            }
            values[0][0] *= h;


            values[1][0] = 0.5 * (functions[i](limits[i].a) + functions[i](limits[i].b));
            for (double x = limits[i].a + h; x <= limits[i].b - h; x += h)
            {
                values[1][0] += functions[i](x);
            }
            values[1][0] *= h;


            values[2][0] = functions[i](limits[i].a) + functions[i](limits[i].b);
            for (double m = 1; m < n; m++)
            {
                if (m % 2 == 0)
                {
                    values[2][0] += 2 * functions[i](limits[i].a + m * h);
                }
                else
                {
                    values[2][0] += 4 * functions[i](limits[i].a + m * h);
                }
            }
            values[2][0] *= h / 3;

            Console.WriteLine(
                $"{values[0][0],10:f4}" +
                $"{values[1][0],10:f4}" +
                $"{values[2][0],10:f4}"
            );
        }
    }
}