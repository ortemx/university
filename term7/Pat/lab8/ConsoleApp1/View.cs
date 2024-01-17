namespace Library;

internal static class View
{
    public static void Menu()
    {
        Console.Clear();
        Console.WriteLine(" Система управления библиотекой ");
        Console.WriteLine("> 1. Список книг");
        Console.WriteLine("> 2. Добавить книгу");
        Console.WriteLine("> 3. Редактировать информацию о книге");
        Console.WriteLine("> 4. Удалить книгу");
        Console.WriteLine("> ENTER Выход");
    }

    public static void ShowAllBooks(List<Book>? books)
    {
        if (books is null)
        {
            Console.WriteLine("Система пока не содержит книг");
            return;
        }

        Console.WriteLine(" ID | Автор                 | Название                          | Изательство          | Год издания  |");
        foreach (var book in books)
        {
            Console.WriteLine($" {book.Id,2} | {book.Author,-21} | {book.Title,-33} |" +
                $" {book.Publisher,-20} | {book.PublicationDate,-13}|");
        }
    }

    public static void ReturnMessage()
    {
        Console.WriteLine("Нажмите ENTER для возврата в главное меню");
        Console.ReadKey();
    }

    public static void SuccessfulAddition()
    {
        Console.WriteLine("Книга успешно добавлена");
    }

    public static void SuccessfulDeletion()
    {
        Console.WriteLine("Книга удалена из системы");
    }

    public static void SuccessfulUpdate()
    {
        Console.WriteLine("Информация о книге успешно обновлена");
    }
}
