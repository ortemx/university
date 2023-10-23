namespace Factory.Factories
{
    using Factory.Domain;

    internal class ResumeFactory : IDocumentFactory
    {
        public Document GetDocument()
        {
            Resume resume = new Resume();
            Console.Write("Name: ");
            resume.Name = Console.ReadLine();
            Console.Write("Contact information: ");
            resume.ContactInformation = Console.ReadLine();
            Console.Write("Experience: ");
            string experience;
            while ((experience = Console.ReadLine()) != string.Empty)
            {
                resume.AddExperience(experience);
            }

            Console.Write("Education: ");
            string education;
            while ((education = Console.ReadLine()) != string.Empty)
            {
                resume.AddEducation(education);
            }

            Console.Write("Skill: ");
            string skill;
            while ((skill = Console.ReadLine()) != string.Empty)
            {
                resume.AddSkill(skill);
            }

            return resume;
        }
    }
}
