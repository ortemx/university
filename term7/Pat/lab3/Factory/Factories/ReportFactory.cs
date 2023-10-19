using Factory.Domain;
using System.Globalization;

namespace Factory.Factories
{
    internal class ReportFactory : IDocumentFactory
    {
        public Document GetDocument()
        {
            Console.Write("Title: ");
            string title = Console.ReadLine();
            Console.Write("Author: ");
            string author = Console.ReadLine();
            Console.WriteLine("Type content");
            string content = Console.ReadLine();
            Console.WriteLine("\nType date in format dd.MM.yyyy HH:mm:ss");
            DateTime date = DateTime.Parse(Console.ReadLine());
            return new Report(title, author, content, date);
        }
    }
}
