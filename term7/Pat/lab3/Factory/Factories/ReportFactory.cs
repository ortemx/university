namespace Factory.Factories
{
    using Factory.Domain;

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
            var iso8601String = "yyyyMMddTHH:mm:ssZ";
            Console.WriteLine("\nType date in format yyyyMMddTHH:mm:ssZ");
            DateTime date = DateTime.ParseExact(Console.ReadLine(), iso8601String, System.Globalization.CultureInfo.InvariantCulture);
            return new Report(title, author, content, date);
        }
    }
}
