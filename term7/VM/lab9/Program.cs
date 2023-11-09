using static System.Random;

double f(double x, double y, double z)
{
    // integral (integral (integral xdx from 1 to 5)dy from 2 to 4)dz from 1 to 2
    return x;
    //integral(integral(integral x * y * y * dx from 1 to 5)dy from 2 to 4)dz from 1 to 2
    //return x * y * y;
    // integral (integral (integral sin(y)*xdx from 1 to 5)dy from 2 to 4)dz from 1 to 2
    //return Math.Sin(y) * x;
}

Limits[] limits = new Limits[]
{
    new Limits { a = 1, b = 5 },
    new Limits { a = 2, b = 4 },
    new Limits { a = 1, b = 2 },
};

int[] n = new int[] { (int)1e4, (int)1e6, (int)1e8 };
double[] values = new double[3] { 0, 0, 0 };

int M = limits.Length;
for (int k = 0; k < n.Length; k++)
{
    double D = 1;
    for (int m = 0; m < M; m++)
    {
        D *= limits[m].b - limits[m].a;
    }

    double t;
    double x;
    double y = 0;
    double z = 0;
    for (int i = 0; i < n[k]; i++)
    {
        t = Shared.NextDouble();
        x = limits[0].a + (limits[0].b - limits[0].a) * t;
        values[k] += f(x, y, z);
    }
    values[k] *= D / n[k];
}

foreach (double v in values)
{
    Console.WriteLine($"{v, 4:f5}");
}
Console.WriteLine($"{Math.Abs(values[0] - values[1]),4:f5}");
Console.WriteLine($"{Math.Abs(values[1] - values[2]),4:f5}");
struct Limits
{
    public double a;
    public double b;
}
