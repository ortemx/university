using System;
using System.Collections.Generic;
using System.Linq;

class Node
{
    public char Symbol { get; set; }
    public double Probability { get; set; }
    public Node Left { get; set; }
    public Node Right { get; set; }
}

class Program
{
    static Node BuildFanoTree(List<Node> symbols)
    {
        if (symbols.Count == 1)
            return symbols[0];

        symbols = symbols.OrderByDescending(s => s.Probability).ToList();

        return BuildFanoTreeHelper(symbols);
    }

    static Node BuildFanoTreeHelper(List<Node> symbols)
    {
        if (symbols.Count == 1)
            return symbols[0];

        double totalProbability = symbols.Sum(s => s.Probability);
        double targetProbability = totalProbability / 2;
        double currentProbability = 0;
        int splitIndex = 0;

        for (int i = 0; i < symbols.Count; i++)
        {
            currentProbability += symbols[i].Probability;
            if (currentProbability >= targetProbability)
            {
                splitIndex = i;
                break;
            }
        }

        List<Node> leftSymbols = symbols.GetRange(0, splitIndex + 1);
        List<Node> rightSymbols = symbols.GetRange(splitIndex + 1, symbols.Count - splitIndex - 1);

        Node leftSubtree = BuildFanoTreeHelper(leftSymbols);
        Node rightSubtree = BuildFanoTreeHelper(rightSymbols);

        Node root = new Node { Symbol = '\0', Probability = totalProbability };
        root.Left = leftSubtree;
        root.Right = rightSubtree;

        return root;
    }

    static Dictionary<char, string> EncodeFanoTree(Node root, string code = "")
    {
        if (root.Symbol != '\0')
            return new Dictionary<char, string> { { root.Symbol, code } };

        Dictionary<char, string> codeMap = new Dictionary<char, string>();
        codeMap = codeMap.Concat(EncodeFanoTree(root.Left, code + "0"))
                         .Concat(EncodeFanoTree(root.Right, code + "1"))
                         .ToDictionary(x => x.Key, x => x.Value);

        return codeMap;
    }

    static void Main()
    {
        string text = "Hello, world!";
        Dictionary<char, double> symbolCounts = new Dictionary<char, double>();

        foreach (char symbol in text)
        {
            if (symbolCounts.ContainsKey(symbol))
                symbolCounts[symbol]++;
            else
                symbolCounts[symbol] = 1;
        }

        List<Node> symbols = symbolCounts.Select(kv => new Node { Symbol = kv.Key, Probability = kv.Value / text.Length }).ToList();
        Node fanoTree = BuildFanoTree(symbols);
        Dictionary<char, string> codeMap = EncodeFanoTree(fanoTree);

        foreach (var kvp in codeMap)
        {
            Console.WriteLine($"Symbol: {kvp.Key}, Code: {kvp.Value}");
        }
    }
}