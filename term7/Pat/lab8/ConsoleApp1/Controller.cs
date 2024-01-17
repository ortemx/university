using Library;

while (true)
{
    View.Menu();
    string command = Console.ReadLine();
    switch (command)
    {
        case "1":
            {
                View.ShowAllBooks(Model.GetAllBooks());
                View.ReturnMessage();
                break;
            };
        case "2":
            {
                Console.WriteLine("Введите информацию о книге или оставьте поле пустым, что вернуться в главное меню:");
                Console.Write("Автор: ");
                string author = Console.ReadLine();
                if (author == "") break;
                Console.Write("Название: ");
                string title = Console.ReadLine();
                if (title == "") break;
                Console.Write("Издательство: ");
                string publisher = Console.ReadLine();
                if (publisher == "") break;
                Console.Write("Год издания: ");
                string publicationDate = Console.ReadLine();
                if (publicationDate == "") break;
                Model.AddBook(author, title, publisher, publicationDate);
                View.SuccessfulAddition();
                View.ReturnMessage();
                break;
            }
        case "3":
            {
                View.ShowAllBooks(Model.GetAllBooks());
                Console.WriteLine("Введите id книги:");
                int id = int.Parse(Console.ReadLine());
                Console.WriteLine("Какое поле вы хотите изменить?" +
                    "\n1 - Автор" +
                    "\n2 – Название" +
                    "\n3 – Издательство" +
                    "\n4 – Год издания");
                string choice = Console.ReadLine();
                string field = choice switch
                {
                    "1" => "author",
                    "2" => "title",
                    "3" => "publisher",
                    "4" => "publicationDate",
                    _ => throw new Exception("Неверное значение"),
                };
                Console.WriteLine("Введите новое значение:");
                string value = Console.ReadLine();
                Model.UpdateBookInfo(id, field, value);
                View.SuccessfulUpdate();
                View.ReturnMessage();
                break;
            }
        case "4":
            {
                View.ShowAllBooks(Model.GetAllBooks());
                Console.WriteLine("Введите id книги:");
                int id = int.Parse(Console.ReadLine());
                Model.DeleteBook(id);
                View.SuccessfulDeletion();
                View.ReturnMessage();
                break;
            }
        default:
            return;
    }
}