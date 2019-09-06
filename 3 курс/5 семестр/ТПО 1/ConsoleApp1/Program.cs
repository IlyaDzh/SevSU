using System;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.Clear();
                Console.WriteLine("Какую задачу выполнить? ");
                Console.WriteLine("1 - Задача №1");
                Console.WriteLine("2 - Задача №2");
                Console.WriteLine("3 - Задача №3");
                int key = int.Parse(Console.ReadLine());

                switch (key)
                {
                    case 1:
                        Matrix();
                        Console.ReadKey();
                        break;
                    case 2:
                        Symbol();
                        Console.ReadKey();
                        break;
                    case 3:
                        TextFile();
                        Console.ReadKey();
                        break;
                    default:
                        Console.Clear();
                        break;
                }
            }
        }

        static void Matrix()
        {
            Console.Clear();
            Console.Write("Введите кол-во строк: ");
            int m = int.Parse(Console.ReadLine());
            Console.Write("Введите кол-во столбцов: ");
            int n = int.Parse(Console.ReadLine());

            int[,] arr = new int[m, n];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write($"Введите [{i}, {j}] элемент: ");
                    arr[i, j] = int.Parse(Console.ReadLine());
                }
            }

            Console.Clear();

            Console.WriteLine("Полученный массив: ");
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write(arr[i, j] + " ");
                }
                Console.Write("\n");
            }

            int count = 0;
            bool exist;
            for (int i = 0; i < m; i++)
            {
                exist = true;
                for (int j = 0; j < n; j++)
                {
                    if (arr[i, j] == 1)
                    {
                        exist = false;
                    }
                }
                if (exist) { count++; }
            }

            Console.WriteLine("Строк не содержащих 1: " + count);
        }

        static void Symbol()
        {
            Console.Clear();
            Console.WriteLine("Введите строку для подсчёта:");
            string inputStr = Console.ReadLine();

            int countForwardSlash = 0;
            int countExclamationMark = 0;


            foreach (var ch in inputStr)
            {
                if (ch == '/')
                    ++countForwardSlash;
                else if (ch == '!')
                    ++countExclamationMark;
            }

            Console.WriteLine("Количество символов / в строке: " + countForwardSlash);
            Console.WriteLine("Количество символов ! в строке: " + countExclamationMark);
        }

        static void TextFile()
        {
            Console.Clear();

            Console.WriteLine("Введите слово, предложение с которым необходимо игнорировать:");
            string word = Console.ReadLine();

            Console.WriteLine("\nРезультат:");

            string[] fileText = File.ReadAllText(Environment.CurrentDirectory + "\\File.txt", Encoding.Default)
            .Split(new char[] { '.' }, StringSplitOptions.RemoveEmptyEntries)
            .Where(x => x.IndexOf(word) == -1).Select(x => x.Trim()).ToArray();

            foreach (string item in fileText)
                Console.WriteLine("{0}.", item);
        }
    }
}
