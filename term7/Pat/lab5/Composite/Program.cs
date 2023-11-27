
Console.WriteLine(Console.WindowWidth); 
internal interface IText
{
    abstract public void Operation();
    abstract public void Add(IText c);
    abstract public void Remove(IText c);
}

internal class Word : IText
{
    public void Operation()
    {
        Console.WriteLine();
    }
    public void Add(IText c)
    {
        throw new InvalidOperationException();
    }
    public void Remove(IText c)
    {
        throw new InvalidOperationException();
    }
}

