internal class Word : IText
{
    private string word = string.Empty;

    internal IText IText
    {
        get => default;
        set
        {
        }
    }

    public Word(string word)
    {
        this.word = word;
    }
    public void Write()
    {
        Console.Write(word);
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
