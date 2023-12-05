/*
pattern chain of responsibility
*/

Article article = new Article("Auto", false);
Handler editorial1 = new Editorial1(null);
Handler editorial2 = new Editorial2(editorial1);
Handler editorial3 = new Editorial3(editorial2);

editorial3.Publish(ref article);

Console.WriteLine(article.readyForPublication);


struct Article
{
    public string type;
    public bool readyForPublication;
    public Article(string type, bool readyForPublication)
    {
        this.type = type;
        this.readyForPublication = readyForPublication;
    }
}
abstract class Handler
{
    protected Handler? successor;
    abstract public void Publish(ref Article article);
}

class Editorial1 : Handler
{
    public Editorial1(Handler? successor)
    {
        this.successor = successor;
    }

    public override void Publish(ref Article  article)
    {
        if (article.type == "Science" || article.type == "Technology")
        {
            article.readyForPublication = true;
        } else if (successor != null) {
            successor.Publish(ref article);
        }
    }
}

class Editorial2 : Handler
{
    public Editorial2(Handler successor)
    {
        this.successor = successor;
    }

    public override void Publish(ref Article  article)
    {
        if (article.type == "Business")
        {
            article.readyForPublication = true;
        } else if(successor != null) {
            successor.Publish(ref article);
        }
    }
}

class Editorial3 : Handler
{
    public Editorial3(Handler successor)
    {
        this.successor = successor;
    }

    public override void Publish(ref Article  article)
    {
        if (article.type == "Beauty")
        {
            article.readyForPublication = true;
        } else if(successor != null) {
            successor.Publish(ref article);
        }
    }
}