using Microsoft.Data.Sqlite;
using static System.Net.Mime.MediaTypeNames;
using System.Xml;

namespace Library;

internal static class Model
{
    private static readonly SqliteConnection connection = new("Data Source = library.db;");

    static Model()
    {
        connection.Open();
        SqliteCommand command = new SqliteCommand($$"""
CREATE TABLE books(
    id              INTEGER PRIMARY KEY AUTOINCREMENT
                            UNIQUE,
    author          TEXT,
    title           TEXT,
    publisher       TEXT,
    publicationDate INTEGER
);
""", connection);
    }
    public static List<Book>? GetAllBooks()
    {
        connection.Open();
        SqliteCommand command = new SqliteCommand("SELECT * FROM books", connection);
        SqliteDataReader reader = command.ExecuteReader();

        if (!reader.HasRows)
        {
            connection.Close();
            return null;
        }

        List<Book> books = new List<Book>();
        while (reader.Read())
        {
            var book = new Book(
                reader.GetInt32(0),
                reader.GetString(1),
                reader.GetString(2),
                reader.GetString(3),
                reader.GetInt32(4)
            );
            books.Add(book);
        }

        return books;
    }

    public static Book? GetBookById(int id)
    {
        connection.Open();
        SqliteCommand command = new SqliteCommand($"SELECT * FROM books WHERE id = {id}", connection);
        SqliteDataReader reader = command.ExecuteReader();
        if (!reader.HasRows)
        {
            connection.Close();
            return null;
        }

        reader.Read();
        return new (
            reader.GetInt32(0),
            reader.GetString(1),
            reader.GetString(2),
            reader.GetString(3),
            reader.GetInt32(4)
        );
    }

    public static void AddBook(string author, string title, string publisher, string publicationDate)
    {
        connection.Open();
        SqliteCommand command = new SqliteCommand(
            $"INSERT INTO books (author, title, publisher, publicationDate) VALUES ('{author}', '{title}', '{publisher}', {publicationDate})",
            connection
        );

        command.ExecuteNonQuery();
        connection.Close();
    }

    public static void UpdateBookInfo(int id, string field, string value)
    {
        connection.Open();
        SqliteCommand command = new SqliteCommand(
            $"UPDATE books SET {field} = '{value}' WHERE id = {id}",
            connection);
        command.ExecuteNonQuery();
        connection.Close();
    }

    public static void DeleteBook(int id)
    {
        connection.Open();
        SqliteCommand command = new SqliteCommand(
            $"DELETE FROM books WHERE id = {id}",
            connection);
        command.ExecuteNonQuery();
        connection.Close();
    }
}
