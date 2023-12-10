using System.Text;

byte[] genePool = Encoding.Default.GetBytes("abcdefghijklmnopqrstuvwxyz ");
byte[] finalChromo = Encoding.Default.GetBytes("the quick brown fox jumps over the lazy dog");
int chromoSize = finalChromo.Length;
int populationSize = 20;
Chromosome[] survivors = new Chromosome[populationSize / 2];
Chromosome[] population = CreatePopulation(populationSize, chromoSize, genePool);
int iterationCount = 0;
while (true)
{
    iterationCount += 1;
    CalcRating(population, finalChromo);
    SortPopulation(population);
    Console.WriteLine($"*** {iterationCount} ***");
    PrintPopulation(population);
    if (population[0].Rating == 0)
    {
        break;
    }
    Select(population, survivors);
    Repopulate(population, survivors, populationSize / 2);
    Mutate(population, 10, 1, genePool);
}
Chromosome[] CreatePopulation(int popSize, int chromoSize, byte[] genePool)
{
    Chromosome[] population = new Chromosome[popSize];
    for (int i = 0; i < popSize; i++)
    {
        population[i] = new Chromosome(chromoSize, genePool);
    }
    return population;
}




void CalcRating(Chromosome[] population, byte[] finalChromo)
{
    foreach (Chromosome chromo in population)
    {
        chromo.Rating = chromo.Size;
        for (int i = 0; i < chromo.Size; i++)
        {
            if (chromo.Genes[i] == finalChromo[i])
            {
                chromo.Rating -= 1;
            }
        }
    }
}

void SortPopulation(Chromosome[] population)
{
    int size = population.Length;
    bool repeat = true;
    while (repeat)
    {
        repeat = false;
        for (int i = 0; i < size - 1; i++)
        {
            Chromosome bubble = population[i];
            if (bubble.Rating > population[i + 1].Rating)
            {
                population[i] = population[i + 1];
                population[i + 1] = bubble;
                repeat = true;
            }
        }
    }
}

void Select(Chromosome[] population, Chromosome[] survivors)
{
    int size = survivors.Length;
    for (int i = 0; i < size; i++)
    {
        survivors[i] = population[i];
    }
}

void Repopulate(Chromosome[] population, Chromosome[] parents, int childrenCount)
{
    int popSize = population.Length;
    while (childrenCount < popSize)
    {
        int p1Pos = GetParentIndex(parents, null);
        int p2Pos = GetParentIndex(parents, p1Pos);
        Chromosome p1 = parents[p1Pos];
        Chromosome p2 = parents[p2Pos];
        population[childrenCount] = Cross(p1, p2);
        population[childrenCount + 1] = Cross(p2, p1);
        childrenCount += 2;
    }
}

int GetParentIndex(Chromosome[] parents, int? excludeIndex)
{
    int size = parents.Length;
    Random rng = new Random();
    while (true)
    {
        int index = rng.Next(0, size);
        if (excludeIndex == null || excludeIndex != index)
        {
            return index;
        }
    }
}

Chromosome Cross(Chromosome chromo1, Chromosome chromo2)
{
    int size = chromo1.Size;
    Random rng = new Random();
    int point = rng.Next(0, size);
    Chromosome child = new Chromosome(size, null);
    for (int i = 0; i < point; i++)
    {
        child.Genes[i] = chromo1.Genes[i];
    }
    for (int i = point; i < size; i++)
    {
        child.Genes[i] = chromo2.Genes[i];
    }
    return child;
}

void Mutate(Chromosome[] population, int chromoCount, int geneCount, byte[] genePool)
{
    int popSize = population.Length;
    int genePoolSize = genePool.Length;
    Random rng = new Random();
    for (int i = 0; i < chromoCount; i++)
    {
        int chromoPos = rng.Next(0, popSize);
        Chromosome chromo = population[chromoPos];
        for (int j = 0; j < geneCount; j++)
        {
            int genePos = rng.Next(0, genePoolSize);
            byte gene = genePool[genePos];
            genePos = rng.Next(0, chromo.Size);
            chromo.Genes[genePos] = gene;
        }
    }
}

void PrintPopulation(Chromosome[] population)
{
    Encoding.GetEncoding(65001);
    int i = 0;
    foreach (Chromosome chromo in population)
    {
        i += 1;
        Console.WriteLine($"{i}. {chromo.Rating}: {Encoding.Default.GetString(chromo.Genes)}");
    }
}

class Chromosome
{
    public int Rating { get; set; }
    public int Size { get; set; }
    public byte[] Genes { get; set; }

    public Chromosome(int size, byte[] genePool)
    {
        Rating = 0;
        Size = size;
        Genes = new byte[size];
        if (genePool != null)
        {
            SetRandomGenes(genePool);
        }
    }

    public void SetRandomGenes(byte[] genePool)
    {
        int genePoolRange = genePool.Length - 1;
        Random rng = new Random();
        for (int i = 0; i < Size; i++)
        {
            int randPos = rng.Next(0, genePoolRange + 1);
            Genes[i] = genePool[randPos];
        }
    }
}