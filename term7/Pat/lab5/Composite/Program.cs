using System.Text;

Header header1 = new Header("Заголовок");
//header1.Write();
Word word1 = new Word("Word1");
Word word2 = new Word("word2");
Word word3 = new Word("word3");
Mark mark1 = new Mark("!");
Sentence sentence1 = new Sentence();
sentence1.Add(word1);
sentence1.Add(word2);
sentence1.Add(mark1);
sentence1.Add(word3);

Word word4 = new Word("Hello");
Word word5 = new Word("There");
Mark mark2 = new Mark("!!!");
Sentence sentence2 = new Sentence();
sentence2.Add(word4);
sentence2.Add(word5);
sentence2.Add(mark2);

Paragraph paragraph = new Paragraph();
paragraph.Add(sentence1);
paragraph.Add(sentence2);


Sentence sentence3 = new Sentence();
sentence3.Add(word1);
sentence3.Add(word2);
sentence3.Add(word3);

Paragraph paragraph2 = new Paragraph();

paragraph2.Add(sentence3);

Text text = new Text();
text.Add(header1);
text.Add(paragraph);
text.Add(paragraph2);
text.Write();

internal class Mark : IText
{
    private string mark = string.Empty;
    public string Value
    {
        get { return mark; }
    }

    internal IText IText
    {
        get => default;
        set
        {
        }
    }

    public Mark(string mark)
    {
        this.mark = mark;
    }
    public void Write()
    {
        Console.Write(mark);
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

internal class Sentence : IText
{
    private List<IText> words;
    public Sentence()
    {
        this.words = new List<IText>();
    }

    internal IText IText
    {
        get => default;
        set
        {
        }
    }

    public void Write()
    {
        for (int i = 0; i < words.Count; i++)
        {
            words[i].Write();
            if (i >= words.Count - 1 || words[i + 1] is not Mark)
            {
                Console.Write("_");
            }
        }
    }
    public void Add(IText t)
    {
        words.Add(t);
    }
    public void Remove(IText t)
    {
        words.Remove(t);
    }
}

internal class Paragraph : IText
{
    private List<IText> sentences;

    public Paragraph()
    {
        this.sentences = new List<IText>();
    }

    internal IText IText
    {
        get => default;
        set
        {
        }
    }

    public void Write()
    {
        Console.Write("\n\t");
        foreach (Sentence sentence in sentences)
        {
            sentence.Write();
        }
    }

    public void Add(IText sentence)
    {
        sentences.Add(sentence);
    }

    public void Remove(IText sentence)
    {
        sentences.Remove(sentence);
    }
}

internal class Header : IText
{
    private string header = string.Empty;
    public Header(string header)
    {
        this.header = header;
    }

    internal IText IText
    {
        get => default;
        set
        {
        }
    }

    public void Write()
    {
        int WindowWidth = Console.WindowWidth;
        if (header.Length <= WindowWidth)
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append(new string(' ', (WindowWidth - header.Length) / 2));
            stringBuilder.Append(header.ToUpper());
            Console.WriteLine(stringBuilder);
        }
        else
        {
            Console.WriteLine($"\t\t{header}");
        }
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

internal class Text : IText
{
    private List<IText> paragraphes;

    public Text()
    {
        paragraphes = new List<IText>();
    }

    internal IText IText
    {
        get => default;
        set
        {
        }
    }

    public void Write()
    {
        foreach (IText paragraph in paragraphes)
        {
            paragraph.Write();
        }
    }

    public void Add(IText text)
    {
        paragraphes.Add(text);
    }

    public void Remove(IText text)
    {
        paragraphes.Remove(text);
    }
}