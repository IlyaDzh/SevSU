using System;
using System.IO;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            _ = new NumSymbolTester();
            Log.Close();
        }
    }

    public class NumberSymbol
    {
        public Tuple<int, int> CheckString(string str)
        {
            int countForwardSlash = 0;
            int countExclamationMark = 0;
            foreach (var ch in str)
            {
                if (ch == '/')
                    ++countForwardSlash;
                else if (ch == '!')
                    ++countExclamationMark;
            }

            return new Tuple<int, int>(countForwardSlash, countExclamationMark);
        }
    }

    public class Log
    {
        private static readonly StreamWriter log = new StreamWriter("result.txt");
        static public void AddString(string s)
        {
            log.WriteLine(s);
        }
        static public void Close()
        {
            log.Close();
        }
    }

    abstract class Tester
    {
        protected void LogMessage(string s)
        {
            Log.AddString(s);
        }
    }

    class NumSymbolTester : Tester
    {
        private readonly NumberSymbol OUT;
        public NumSymbolTester()
        {
            OUT = new NumberSymbol();
            Run();
        }
        private void Run()
        {
            StringTest1();
        }
        private void StringTest1()
        {
            string[] strings = {
                "Тест",
                "!",
                "/",
                "Тест /!/ тест",
                "Тест!",
                "!/Тест",
                "///!//!!!!/////!!!!!!!!!!!!!!///!/"
            };

            foreach (var str in strings)
            {
                var result = OUT.CheckString(str);
                Log.AddString($"Строка: {str}");
                Log.AddString($"Количество символов /: {result.Item1}");
                Log.AddString($"Количество символов !: {result.Item2}");
                Log.AddString("------------------------------------------");
            }
        }
    }
}