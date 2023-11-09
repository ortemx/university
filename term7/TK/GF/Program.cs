/*
φ = x^4 + x + 1 <-> 10011

пример 1
1011 * 0010 <-> (x^3+x+1) * x = x^4 + x^2 + x ≡
≡ x^4 + x^2 + x + φ =
= x^4 + x^2 + x + x^4 + x + 1 = 
= x^2 + 1 <-> 0101 = 5


00001011    (11)        00000010    (2)
00000010     (2)        00000011    (3)
________*               ________*
00000000     (0)        00000010    (2)
00010110    (22)        00000100    (4)
________^               ________^
00010110    (22)        00000110    (6)
00010011    (19)        00010011   (19)
________^               ________^
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


using System.Collections;
using System.Text;

string BitArrayToString(BitArray bits)
{
    StringBuilder sb = new StringBuilder();

    for (int i = bits.Length - 1; i >= 0; i--)
    {
        sb.Append(bits[i] ? "1" : "0");
    }
    return sb.ToString();

}

BitArray BitArrayMultyply(BitArray z1, BitArray z2)
{
    BitArray rez = new(z1.Length);
    for (int i = 0; i < z2.Length; i++)
    {
        if (z2[i])
        {
            for (int j = 0; j < z1.Length - i; j++)
            {
                rez[j + i] ^= z1[j];
            }
        }
    }
    return rez;
}

int k = 4;
int n = 2;
BitArray φ = new(new byte[] { 0b10011 });
// first row
Console.Write("     | ");
for (int j = 0; j < Math.Pow(n, k); j++)
{
    Console.Write(Convert.ToString(j, 2).PadLeft(4, '0') + " | ");
}
Console.WriteLine("");

for (byte i = 0; i < Math.Pow(n, k); i++)
{
    string output = Convert.ToString(i, 2).PadLeft(4, '0') + " | ";
    for (byte j = 0; j < Math.Pow(n, k); j++)
    {
        BitArray z1 = new(new byte[] { i });
        BitArray z2 = new(new byte[] { j });
        BitArray rez = BitArrayMultyply(z1, z2);
        if (rez[k] == true)
        {
            rez = rez.Xor(φ);
        }
        output += BitArrayToString(rez)[^4..] + " | ";
    }
    Console.WriteLine(output);
}
