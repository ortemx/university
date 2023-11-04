/*
φ = x^4 + x + 1 <-> 10011

пример 1
1011 * 0010 <-> (x^3+x+1) * x = x^4 + x^2 + x ≡
≡ x^4 + x^2 + x + φ =
= x^4 + x^2 + x + x^4 + x + 1 = 
= x^2 + 1 <-> 0101 = 5


00001011    (11)
00000010     (2)
________*
00010110    (22)
00010011    (19)
________^
00000101     (5)

пример 2
1011 * 0011 <-> (x^3+x+1) * (x+1) = 
= x^4 + x^3 + x^2 + 2x + 1 <-> 11101
x^4 + x^3 + x^2 + 2x + 1 + x^4 + x + 1 =
x^3 + x^2 + x <-> 1110

00001011    (11)
00000011     (3)
________*
00001011    (11)
0001011     (22)
________^
00011101    (29)
00010011    (19)
________^
00001110    (14)


φ <-> 19
1011 <-> 11
0010 <->  2
11 * 2 % 19 = 3 <-> 0011
*/


// Console.WriteLine(0b1011 * 0b0010 ^ 0b10011);

// int k = 5;
// int n = 2;
// var φ = 10011;
// // first row
// Console.Write("     | ");
// for (int j = 0; j < Math.Pow(n, k-1); j++){
//     Console.Write(Convert.ToString(j, 2).PadLeft(4, '0') + " | ");
// }
// Console.WriteLine("");

// for (int i = 0; i < Math.Pow(n, k-1); i++)
// {   
//     var result = Convert.ToString(i, 2).PadLeft(4, '0') + " | ";
//     for (int j = 0; j < Math.Pow(n, k-1); j++){
//         var z1 = i.;
//         var z2 = j.ToBitArray();
//         Console.WriteLine(z1 + " * " + z2);
//         // var r = z1 * z2 ^ φ;
//         // result += Convert.ToString(r, 2).PadLeft(4, '0') + " | ";        
//     }
//     Console.WriteLine(result);
// }

// Console.WriteLine(Convert.ToString(0b0110 ^ 0b1101, 2));

static string MultiplyAndXOR(string number1, string number2)
{
    // Преобразуем строки в массив байтов
    byte[] bytes1 = Convert.FromBase64String(Convert.ToBase64String(number1.PadRight(8, '0').ToCharArray()));
    byte[] bytes2 = Convert.FromBase64String(Convert.ToBase64String(number2.PadRight(8, '0').ToCharArray()));

    // Умножаем числа и выполняем ксорирование
    byte[] resultBytes = new byte[8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((bytes1[i] & (1 << (7 - j))) != 0 && (bytes2[j] & (1 << (7 - i))) != 0)
            {
                resultBytes[i] ^= (byte)(1 << (7 - j));
            }
        }
    }

    // Преобразуем результат обратно в строку
    string result = Convert.ToBase64String(resultBytes).TrimEnd('=').Replace('+', '0').Replace('/', '1');

    return result;
}

string number1 = "00001011"; // 11 в двоичном виде
string number2 = "00000011"; // 3 в двоичном виде

string result = MultiplyAndXOR(number1, number2);

Console.WriteLine("Результат: " + result);