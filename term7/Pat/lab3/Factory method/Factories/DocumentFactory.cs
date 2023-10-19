using Documents.Domain;

namespace Documents.Factories
{
    internal interface  IDocumentFactory
    {
        Document GetDocument();
    }
}
