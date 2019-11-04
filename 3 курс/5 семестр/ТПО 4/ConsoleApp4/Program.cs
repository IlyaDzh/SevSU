using System;
using System.IO;
using System.Linq;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            Tester tester = new Tester();
            tester.RunTest();

            Console.ReadLine();
        }
    }

    class Tester
    {
        private static readonly StreamWriter log = new StreamWriter("log.log");
        static public void Log(string msg)
        {
            log.WriteLine(msg);
        }
        static public void Close()
        {
            log.Close();
        }
        public void RunTest()
        {
            TextReaderTest();
            Close();
        }
        public void TextReaderTest()
        {
            TextWriter text = new TextWriter
            {
                allText = "Таким образом консультация с широким активом обеспечивает широкому кругу (специалистов) участие в формировании систем массового участия. С другой стороны дальнейшее развитие различных форм деятельности требуют определения и уточнения существенных финансовых и административных условий. Таким образом сложившаяся структура организации способствует подготовки и реализации соответствующий условий активизации. С другой стороны дальнейшее развитие различных форм деятельности представляет собой интересный эксперимент проверки существенных финансовых и административных условий.",
                ignor = "другой",
                outText = "Таким образом консультация с широким активом обеспечивает широкому кругу (специалистов) участие в формировании систем массового участия. Таким образом сложившаяся структура организации способствует подготовки и реализации соответствующий условий активизации. "
            };
            text.Save("out.txt");

            TextReader textReader = new TextReader();
            TextWriter readTextFromFile = textReader.ReadText("out.txt");

            if (text.outText == readTextFromFile.outText)
            {
                Console.WriteLine("Тест интеграции пройден!");
                Log("Тест интеграции пройден!");
            }
            else
            {
                Console.WriteLine("Тест интеграции провален!");
                Log("Тест интеграции провален!");
            }
        }
    }

    class TextReader
    {
        public TextWriter ReadText(string filename)
        {
            TextWriter test = new TextWriter
            {
                outText = File.ReadAllText(filename)
            };
            return test;
        }
    }

    class TextWriter
    {
        public string allText;
        public string ignor;
        public string outText;

        public void Save(string result)
        {
            string[] fileText = allText
            .Split(new char[] { '.' }, StringSplitOptions.RemoveEmptyEntries)
            .Where(x => x.IndexOf(ignor) == -1).Select(x => x.Trim()).ToArray();

            foreach (string item in fileText)
                File.AppendAllText(result, $"{item}. ");
        }
    }
}