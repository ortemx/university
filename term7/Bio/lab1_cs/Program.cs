
int population_size = 100;
int max_generation = 100;
double mutation_rate = 0.01;
double selection_rate = 0.2;

Gene[] population = create_population(population_size);

for (int i = 0; i < max_generation; i++)
{
    evaluate_fitness(population);
    var average_fitness = calculate_average_fitness(population);
    Console.WriteLine(
        $"Generation: {i}," +
        $" Best Fitness: {FindBestGene(population).Fitness}," +
        $" Average Fitness: {average_fitness}");
    var parents = SelectParents(population, selection_rate);
    population = GenerateNextGeneration(parents, population_size, mutation_rate);
}

var best_gene = FindBestGene(population);
best_gene.Fitness = equation(best_gene.X, best_gene.Y);
Console.WriteLine($"Best Gene: {best_gene}");

Gene[] create_population(int population_size)
{
    Gene[] genes = new Gene[population_size];
    Random random = new Random();

    for (int i = 0; i < population_size; i++)
    {
        genes[i] = new Gene(
            random.NextDouble() * 10,
            random.NextDouble() * 10,
            0.0);
    }

    return genes;
}

void evaluate_fitness(Gene[] population)
{
    foreach (Gene gene in population)
    {
        gene.Fitness = equation(gene.X, gene.Y);
    }
}
Gene[] SelectParents(Gene[] population, double selectionRate)
{
    Random random = new Random();

    Gene[] sortedPopulation = population;
    Array.Sort(sortedPopulation, (x, y) => y.Fitness.CompareTo(x.Fitness));
    int numberOfParents = (int)(population.Length * selectionRate);
    Gene[] parents = sortedPopulation[..numberOfParents];
    random.Shuffle(parents);
    return parents;
}
Gene[] GenerateNextGeneration(Gene[] parents, int size, double mutationRate)
{
    Random rng = new Random();
    Gene[] nextGeneration = new Gene[size];

    for (int i = 0; i < size; i++)
    {
        Gene parent1 = parents[rng.Next(parents.Length)];
        Gene parent2 = parents[rng.Next(parents.Length)];

        Gene child = Crossover(parent1, parent2);
        Mutate(rng, ref child, mutationRate);

        nextGeneration[i] = child;
    }

    return nextGeneration;
}

Gene Crossover(Gene parent1, Gene parent2)
{
    Random rng = new Random();
    double x = rng.Next(2) == 0 ? parent1.X : parent2.X;
    double y = rng.Next(2) == 0 ? parent1.Y : parent2.Y;
    return new Gene(x, y, 0.0);
}


void Mutate(Random rng, ref Gene gen, double mutationRate)
{
    if (rng.NextDouble() < mutationRate)
    {
        double xMutation = rng.NextDouble() * 0.2 - 0.1;
        gen.X += xMutation;
        gen.X = Math.Max(0.0, Math.Min(10.0, gen.X));

        double yMutation = rng.NextDouble() * 0.2 - 0.1;
        gen.Y += yMutation;
        gen.Y = Math.Max(0.0, Math.Min(10.0, gen.Y));
    }
}

Gene? FindBestGene(Gene[] population)
{
    Gene? bestGene = population
      .OrderByDescending(gene => gene.Fitness)
      .FirstOrDefault();

    if (bestGene == null)
    {
        throw new Exception("Unable to find the best gene");
    }

    return bestGene;
}

double calculate_average_fitness(Gene[] population) => population.Average(gen => gen.Fitness);

double equation(double x, double y) => 6.0 * x - x * x + 4.0 * y - y * y;

class Gene
{
    public double X { get; set; }
    public double Y { get; set; }
    public double Fitness { get; set; }
    public Gene(double x, double y, double fitness)
    {
        X = x;
        Y = y;
        Fitness = fitness;
    }

    public override string ToString()
    {
        return $"X: {X}, Y: {Y}, Fitness: {Fitness}";
    }
}