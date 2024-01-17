namespace Library;

internal class Book
{
    private int _id;
    private string _author;
    private string _title;
    private string _publisher;
    private int _publicationDate;

    public Book(int id, string author, string title, string publisher, int publicationDate)
    {
        _id = id;
        _author = author;
        _title = title;
        _publisher = publisher;
        _publicationDate = publicationDate;
    }

    public int Id => _id;
    public string Author => _author;
    public string Title => _title;
    public string Publisher => _publisher;
    public int PublicationDate => _publicationDate;
}
