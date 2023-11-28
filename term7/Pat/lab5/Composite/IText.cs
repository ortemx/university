
//paragraph2.Write();
//sentence1.Write();
//Sentence sentence2 = new Sentence(new List<string> { "hello", "there" });
//sentence2.Write();
interface IText
{
    abstract public void Write();
    abstract public void Add(IText text);
    abstract public void Remove(IText text);
}
