using Factory.Domain;

namespace Factory.Factories
{
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
            string Experience;
            while ((Experience = Console.ReadLine()) != string.Empty)
            {
                resume.AddExperience(Experience);
            }
            Console.Write("Education: ");
            string Education;
            while ((Education = Console.ReadLine()) != string.Empty)
            {
                resume.AddEducation(Education);
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
