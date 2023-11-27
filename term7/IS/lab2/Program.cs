// See https://aka.ms/new-console-template for more information
string[] questions =
{
    "Марка автомобиля иностранная?",
    "Марка специализируется на грузовиках?",
    "Марка изветсна электрокарами?",
    "Марка известна внедорожниками?",
    "Автомобили Вашей марки учавствуют в ралли Дакар?",
    "Марка машины представленна в Формуле1?",
    "Компания владелец марки известна так же космическими технологиями?",
    "Марка принадлежала французскому концерну?"
};

string[] answers =
{
    "Lada", "УАЗ", "ЗИЛ", "КАМАЗ", "Toyota", "Mercedes-Benz", "Li Auto", "Tesla", "Москвич"
};

string[] positiveAnswers =
{
    "+", "y", "yes", "да", "д"
};

double probability;

string? answer = string.Empty;
while (true)
{
    probability = 1;
    Console.WriteLine(questions[0]);
    answer = Console.ReadLine();
    if (positiveAnswers.Contains(answer))
    {
        probability *= 0.5;
        Console.WriteLine(questions[2]);
        answer = Console.ReadLine();
        if (positiveAnswers.Contains(answer))
        {
            probability *= 0.5;
            Console.WriteLine(questions[6]);
            answer = Console.ReadLine();
            if (positiveAnswers.Contains(answer))
            {
                probability *= 0.5;
                Console.WriteLine(answers[7]);
            }
            else
            {
                probability *= 0.5;
                Console.WriteLine(answers[6]);
            }
        }
        else
        {
            probability *= 0.5;
            Console.WriteLine(questions[5]);
            answer = Console.ReadLine();
            if (positiveAnswers.Contains(answer))
            {
                probability *= 0.5;
                Console.WriteLine(answers[5]);
            }
            else
            {
                probability *= 0.5;
                Console.WriteLine(answers[4]);
            }
        }
    }
    else
    {
        probability *= 0.5;
        Console.WriteLine(questions[1]);
        answer = Console.ReadLine();
        if (positiveAnswers.Contains(answer))
        {
            probability *= 0.5;
            Console.WriteLine(questions[4]);
            answer = Console.ReadLine();
            if (positiveAnswers.Contains(answer))
            {
                probability *= 0.5;
                Console.WriteLine(answers[3]);
            }
            else
            {
                probability *= 0.5;
                Console.WriteLine(answers[2]);
            }
        }
        else
        {
            probability *= 0.5;
            Console.WriteLine(questions[3]);
            answer = Console.ReadLine();
            if (positiveAnswers.Contains(answer))
            {
                probability *= 0.5;
                Console.WriteLine(answers[1]);
            }
            else
            {
                probability *= 0.5;
                Console.WriteLine(questions[7]);
                answer = Console.ReadLine();
                if (positiveAnswers.Contains(answer))
                {
                    probability *= 0.5;
                    Console.WriteLine(answers[0]);
                }
                else
                {
                    probability *= 0.5;
                    Console.WriteLine(answers[8]);
                }                
            }
        }
    }
    Console.WriteLine($"Вероятность получения результата: {probability}\nПовторить?");
    answer = Console.ReadLine();
    if (!positiveAnswers.Contains(answer)) break;
}
