using Factory.Domain;

namespace Factory.Factories
{
    internal class LetterFactory : IDocumentFactory
    {
        public Document GetDocument()
        {
            Console.Write("Sender: ");
            string sender = Console.ReadLine();
            Console.Write("Recepient: ");
            string recepient = Console.ReadLine();
            Console.WriteLine("Type content");
            string content = Console.ReadLine();

            return new Letter(sender, recepient, content, DateTime.Now);
        }
    }
}
