namespace XMLParce;

using System.Xml;

public partial class Form1 : Form
{
    string rowTextPath = string.Empty;
    string styleFilePath = string.Empty;

    public Form1()
    {
        InitializeComponent();
        listBox1.IntegralHeight = true;
    }

    private void button1_Click(object sender, EventArgs e)
    {
        OpenFileDialog openFileDialog = new()
        {
            Filter = "Ôאיכû XML (*.xml)|*.xml"
        };

        if (openFileDialog.ShowDialog() == DialogResult.OK)
        {
            rowTextPath = openFileDialog.FileName;
            button1.Text = Path.GetFileName(rowTextPath);

        }
    }

    private void ProcessXmlFile(string rowTextFile)
    {
        XmlDocument xmlDocument = new();
        xmlDocument.Load(rowTextFile);

        //using XmlNodeList nodes = xmlDocument.SelectNodes("/style/p");
        using XmlNodeList? nodes = xmlDocument.SelectNodes("/document/*");
        listBox1.Items.Add("start" + "\n");

        if (nodes is null)
        {
            return;
        }

        foreach (XmlNode node in nodes)
        {
            if (node is null) { continue; }

            string nodeName = node.Name;
            string value = string.Empty;
            listBox1.Items.Add(nodeName);

            switch (nodeName)
            {
                case "h":
                    if (node.Attributes is null)
                    {
                        break;
                    }
                    string level = node.Attributes["lvl"]?.Value ?? "1";
                    listBox1.Items.Add(level);
                    value = node.InnerText.Trim();
                    break;

                case "p":
                    value = node.InnerText.Trim();
                    break;

                case "ol":
                    if (node.Attributes is null)
                    {
                        break;
                    }
                    string type = node.Attributes["type"]?.Value ?? string.Empty;
                    string sep = node.Attributes["sep"]?.Value ?? string.Empty;

                    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                    int index = 1;
                    XmlNodeList liNodes = node.SelectNodes("li");
                    foreach (XmlNode liNode in liNodes)
                    {
                        string begin = string.Empty;
                        if (type == "num")
                        {
                            begin = index.ToString() + sep;
                        }
                        if (type == "abc")
                        {
                            begin = alphabet.ToLower()[index - 1] + sep;
                        }

                        string listItem = liNode.InnerText;
                        listBox1.Items.Add(begin + listItem);
                        index++;
                    }
                    break;

                case "ul":
                    liNodes = node.SelectNodes("li");
                    foreach (XmlNode liNode in liNodes)
                    {
                        string listItem = liNode.InnerText;
                        listBox1.Items.Add(listItem);
                    }
                    break;

                case "code":
                    if (node.Attributes is null)
                    {
                        break;
                    }
                    string lang = node.Attributes["lang"]?.Value ?? string.Empty;
                    listBox1.Items.Add(lang);
                    value = node.InnerText.Trim();
                    break;

                case "math":
                    value = node.InnerText.Trim();
                    break;

                case "img":
                    if (node.Attributes is null)
                    {
                        break;
                    }
                    string src = node.Attributes["src"]?.Value ?? string.Empty;
                    string description = node.Attributes["desc"]?.Value ?? string.Empty;
                    listBox1.Items.Add(description);
                    listBox1.Items.Add(src);
                    break;

                case "table":
                    if (node is null || node.Attributes is null)
                    {
                        break;
                    }
                    description = node.Attributes["desc"]?.Value ?? string.Empty;
                    listBox1.Items.Add(description);

                    XmlNodeList thNodes = node.SelectNodes("th");
                    XmlNodeList trNodes = node.SelectNodes("tr");
                    foreach (XmlNode thNode in thNodes)
                    {
                        XmlNodeList? tdNodes = thNode.SelectNodes("td");
                        if (tdNodes != null)
                        {
                            string[] thValues = tdNodes.Cast<XmlNode>()
                                .Select(tdNode => tdNode.InnerText)
                                .ToArray();
                            listBox1.Items.AddRange(thValues);
                        }
                    }
                    foreach (XmlNode trNode in trNodes)
                    {
                        string[] rowValues = trNode.SelectNodes("td").Cast<XmlNode>().Select(tdNode => tdNode.InnerText).ToArray();
                        listBox1.Items.AddRange(rowValues);
                    }
                    break;

                default:
                    break;
            }

            listBox1.Items.Add("\t" + value);
        }
    }

    private void button2_Click(object sender, EventArgs e)
    {
        OpenFileDialog openFileDialog = new()
        {
            Filter = "Ôאיכû XML (*.xml)|*.xml"
        };

        if (openFileDialog.ShowDialog() == DialogResult.OK)
        {
            styleFilePath = openFileDialog.FileName;
            button2.Text = Path.GetFileName(rowTextPath);
        }
    }

    private void button3_Click(object sender, EventArgs e)
    {
        if (rowTextPath == string.Empty && styleFilePath == string.Empty) 
        {
            label3.Text = "פאיכû םו גûבנאםû";
            return;
        }

        ProcessXmlFile(rowTextPath);
    }
}
