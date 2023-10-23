namespace Factory.Domain
{
    internal class Report : Document
    {
        public Report(string title, string author, string content, DateTime date)
        {
            this.type = "Report";
            this.Title = title;
            this.Author = author;
            this.Content = content;
            this.Date = date;
        }

        public string Title { get; set; }

        public string Author { get; set; }

        public string Content { get; set; }

        public DateTime Date { get; set; }

        public override string ToString()
        {
            return "Type: " + this.type
                + "\nTitle: " + this.Title
                + "\nAuthor: " + this.Author
                + "\nContent\n" + this.Content
                + "\nDate: " + this.Date.ToString();
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
