using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata;
using System.Text;
using System.Threading.Tasks;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace Factory.Domain
{
    internal class Resume : Document
    {
        public string Name { get; set; }
        public string ContactInformation { get; set; }
        public List<string> Experience { get; set; }
        public List<string> Education { get; set; }
        public List<string> Skills { get; set; }

        public Resume()
        {
            Experience = new List<string>();
            Education = new List<string>();
            Skills = new List<string>();
        }
        public void AddExperience(string experience)
        {
            Experience.Add(experience);
        }

        public void AddEducation(string education)
        {
            Education.Add(education);
        }

        public void AddSkill(string skill)
        {
            Skills.Add(skill);
        }

        public void CreatePDF()
        {
            // Логика для создания PDF-файла
        }
        public override string ToString()
        {
            return "Type: " + type
                + "\nName: " + Name
                + "\nContact information: " + ContactInformation
                + "\nExperience: " + string.Join(", ", Experience)[..^2]
                + "\nEducation: " + string.Join(", ", Education)[..^2]
                + "\nSkills: " + string.Join(", ", Skills)[..^2];
        }
    }
}
