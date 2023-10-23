namespace Factory.Domain
{
    internal class Letter : Document
    {
        private string sender;
        private string recipient;
        private string content;
        private DateTime date;

        public Letter(string sender, string recipient, string content, DateTime date)
        {
            this.type = "Letter";
            this.sender = sender;
            this.recipient = recipient;
            this.content = content;
            this.date = date;
        }

        public override string ToString()
        {
            return "Type: " + this.type
                + "\nSender: " + this.sender
                + "\nRecepient: " + this.recipient
                + "\nContent\n" + this.content
                + "\nDate: " + this.date.ToString();
        }
    }
}
