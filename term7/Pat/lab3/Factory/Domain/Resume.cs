namespace Factory.Domain
{
    internal class Resume : Document
    {
        public Resume()
        {
            this.type = "Resume";
            this.Experience = new List<string>();
            this.Education = new List<string>();
            this.Skills = new List<string>();
        }

        public string Name { get; set; }

        public string ContactInformation { get; set; }

        public List<string> Experience { get; set; }

        public List<string> Education { get; set; }

        public List<string> Skills { get; set; }

        public void AddExperience(string experience)
        {
            this.Experience.Add(experience);
        }

        public void AddEducation(string education)
        {
            this.Education.Add(education);
        }

        public void AddSkill(string skill)
        {
            this.Skills.Add(skill);
        }

        // public void CreatePDF()
        // {
        //    // Логика для создания PDF-файла
        // }
        public override string ToString()
        {
            return "Type: " + this.type
                + "\nName: " + this.Name
                + "\nContact information: " + this.ContactInformation
                + "\nExperience: " + string.Join(", ", this.Experience)
                + "\nEducation: " + string.Join(", ", this.Education)
                + "\nSkills: " + string.Join(", ", this.Skills);
        }
    }
}
