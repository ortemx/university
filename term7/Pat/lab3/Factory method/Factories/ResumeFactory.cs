using Documents.Domain;

namespace Documents.Factories
{
    internal class ResumeFactory : DocumentFactory
    {
        private readonly var property1;
        private readonly string property2;

        public ResumeFactory(var property1, string property2)
        {
            this.property1 = property1;
            this.property2 = property2;
        }

        public override IDocument GetDocument()
        {
            Resume document = new(property1, property2)
            {
                Description = description
            };

            return document;
        }
    }
}