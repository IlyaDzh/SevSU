using System;

namespace SymbolsLib
{
    public class Symbols
    {
        private string str;
        public int countForwardSlash = 0;
        public int countExclamationMark = 0;

        public Symbols(string _str)
        {
            str = _str;
        }

        public Tuple<int, int> CheckAndPrint()
        {
            Check(str);

            Console.WriteLine("Количество символов / в строке: " + countForwardSlash);
            Console.WriteLine("Количество символов ! в строке: " + countExclamationMark);

            return new Tuple<int, int>(countForwardSlash, countExclamationMark);
        }

        public void Check(string str)
        {
            foreach (var ch in str)
            {
                if (ch == '/')
                    ++countForwardSlash;
                else if (ch == '!')
                    ++countExclamationMark;
            }
        }
    }
}