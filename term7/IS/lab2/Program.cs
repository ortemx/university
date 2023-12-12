using static System.Console;

string[] answers =
{
    "Lada", "УАЗ", "ЗИЛ", "КАМАЗ", "Toyota", "Mercedes-Benz", "Li Auto", "Tesla", "Москвич"
};

string[] positiveAnswers =
{
    "+", "y", "yes", "да", "д"
};

double probability;
while (true)
{
    probability = 1;
    WriteLine("Марка автомобиля иностранная?");
    if (positiveAnswers.Contains(ReadLine()))
    {
        probability *= 0.8;
        WriteLine("Марка известна электрокарами?");        
        if (positiveAnswers.Contains(ReadLine()))
        {
            probability *= 0.1;
            WriteLine("Компания владелец марки известна так же космическими технологиями?");            
            if (positiveAnswers.Contains(ReadLine()))
            {
                probability *= 0.05;
                WriteLine(answers[7]);
            }
            else
            {
                probability *= 0.95;
                WriteLine(answers[6]);
            }
        }
        else
        {
            probability *= 0.9;
            WriteLine("Марка машины представленна в Формуле1?");            
            if (positiveAnswers.Contains(ReadLine()))
            {
                probability *= 0.2;
                WriteLine(answers[5]);
            }
            else
            {
                probability *= 0.8;
                WriteLine(answers[4]);
            }
        }
    }
    else
    {
        probability *= 0.2;
        WriteLine("Марка специализируется на грузовиках?");        
        if (positiveAnswers.Contains(ReadLine()))
        {
            probability *= 0.3;
            WriteLine("Автомобили Вашей марки учавствуют в ралли Дакар?");            
            if (positiveAnswers.Contains(ReadLine()))
            {
                probability *= 0.1;
                WriteLine(answers[3]);
            }
            else
            {
                probability *= 0.9;
                WriteLine(answers[2]);
            }
        }
        else
        {
            probability *= 0.7;
            WriteLine("Марка известна внедорожниками?");            
            if (positiveAnswers.Contains(ReadLine()))
            {
                probability *= 0.5;
                WriteLine(answers[1]);
            }
            else
            {
                probability *= 0.5;
                WriteLine("Марка принадлежала французскому концерну?");                
                if (positiveAnswers.Contains(ReadLine()))
                {
                    probability *= 0.9;
                    WriteLine(answers[0]);
                }
                else
                {
                    probability *= 0.1;
                    WriteLine(answers[8]);
                }                
            }
        }
    }
    WriteLine($"Вероятность получения результата: {probability}\nПовторить?");    
    if (!positiveAnswers.Contains(ReadLine())) break;
}
