using static System.Math;

List<Function> functions = new()
{
    (x) => Log(Cos(1/(x*x))),
    (x) => Log(x)*Sin(1/(x*x))
};

List<Limits> limits = new()
{
    new Limits() { a = 1, b = 2 },
    new Limits() { a = 1, b = 2 }
};

Dictionary<double, double> notes_3 = new()
{
    {0, 8f / 9},
    {0.7746, 5f / 9 },
    {-0.7746, 5f / 9 },
};

Dictionary<double, double> notes_4 = new()
{
    {0.34, 0.6521 },
    {-0.34, 0.6521 },
    {0.8611, 0.3479 },
    {-0.8611, 0.3479 },
};

Dictionary<double, double> notes_5 = new()
{
    {0, 0.5689 },
    {0.5385, 0.4786 },
    {-0.5385, 0.4786 },
    {0.9062, 0.2369 },
    {-0.9062, 0.2369 },
};


// row - note, column - function
List<double[]> values = new() {
    new double[] {0, 0},
    new double[] {0, 0},
    new double[] {0, 0},
};

for (int i = 0; i < functions.Count; i++)
{
    foreach (var note in notes_3)
    {
        double x = 0.5 * ((limits[i].b - limits[i].a) * note.Key + limits[i].b + limits[i].a);
        values[0][i] += note.Value * functions[i](x);
    }
    values[0][i] *= 0.5 * (limits[i].b - limits[i].a);

    foreach (var note in notes_4)
    {
        double x = 0.5 * ((limits[i].b - limits[i].a) * note.Key + limits[i].b + limits[i].a);
        values[1][i] += note.Value * functions[i](x);
    }
    values[1][i] *= 0.5 * (limits[i].b - limits[i].a);

    foreach (var note in notes_5)
    {
        double x = 0.5 * ((limits[i].b - limits[i].a) * note.Key + limits[i].b + limits[i].a);
        values[2][i] += note.Value * functions[i](x);
    }
    values[2][i] *= 0.5 * (limits[i].b - limits[i].a);
}

Console.WriteLine("\tLog(Cos(1/(x*x)))\n");
Console.WriteLine(" n |        I_n |      I_n+1 | |I_n+1 - I_n");
Console.WriteLine("---+------------+------------+-------------");
Console.WriteLine($" {3} | {values[0][0],10:f6} | {values[1][0],10:f6} | {Abs(values[1][0] - values[0][0]),12:f6}");
Console.WriteLine($" {4} | {values[1][0],10:f6} | {values[2][0],10:f6} | {Abs(values[2][0] - values[1][0]),12:f6}");
Console.WriteLine($" {5} | {values[2][0],10:f6} |            |");

Console.WriteLine("\n\tLog(x)*Sin(1/(x*x))\n");
Console.WriteLine(" n |        I_n |      I_n+1 | |I_n+1 - I_n");
Console.WriteLine("---+------------+------------+-------------");
Console.WriteLine($" {3} | {values[0][1],10:f6} | {values[1][1],10:f6} | {Abs(values[1][1] - values[0][1]),12:f6}");
Console.WriteLine($" {4} | {values[1][1],10:f6} | {values[2][1],10:f6} | {Abs(values[2][1] - values[1][1]),12:f8}");
Console.WriteLine($" {5} | {values[2][1],10:f6} |            |");

struct Limits
{
    public double a;
    public double b;
}
delegate double Function(double x);