using static System.Runtime.InteropServices.JavaScript.JSType;
using System.Reflection;

namespace Factory.Domain
{
    internal class Report : Document
    {
        public string Title { get; set; }
        public string Author { get; set; }
        public string content { get; set; }
        public DateTime date { get; set; }

        public Report(string title, string author, string content, DateTime date)
        {
            type = "Report";
            Title = title;
            Author = author;
            this.content = content;
            this.date = date;
        }

        public override string ToString()
        {
            return "Type: " + type
                + "\nTitle: " + Title
                + "\nAuthor: " + Author
                + "\nContent\n" + content
                + "\nDate: " + date.ToString();
        }
        // public void GenerateSummary()
        // {
        //     // Логика для генерации сводки
        // }

        // public void AddSection(string section)
        // {
        //     Sections.Add(section);
        // }

        // public void ExportToCSV()
        // {
        //     // Логика для экспорта в CSV-файл
        // }
    }
}
