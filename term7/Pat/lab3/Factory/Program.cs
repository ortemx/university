using Factory.Domain;
using Factory.Factories;

Console.WriteLine(">>> Welcome to Document Creator <<<\n" +
    "> Enter Your type of the Dcument\n" +
    "> Resume\n> Report\n> Letter");

string? documentType = Console.ReadLine();

if (documentType == null)
{
    Console.WriteLine("Invalid type");
    return;
}
IDocumentFactory factory = documentType.ToLower() switch
{
    "resume" => new ResumeFactory(),
    "letter" => new LetterFactory(),
    "report" => new ReportFactory(),
    _ => throw new NotImplementedException(),
};

Document document = factory.GetDocument();

Console.WriteLine("Document has been created\n" + document.ToString());

