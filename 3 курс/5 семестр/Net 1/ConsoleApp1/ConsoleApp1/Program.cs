using System;
using System.Linq;
using System.Text.RegularExpressions;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите размерность матрицы: ");
            int size = Int32.Parse(Console.ReadLine());

            #region Задание 1 (4 вариант)
            //2.4.	В двухмерном массиве вещественных чисел поменять местами строки и столбцы с одинаковыми номерами.
            Console.WriteLine("\nИсходный массив:");
            double[,] arr = new double[size, size];
            Random rnd = new Random();
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    arr[i, j] = rnd.NextFloat(-10, 10);
            PrintArray(arr);

            Console.WriteLine("\nЗадание 1");
            for (int i = 0; i < arr.GetLength(0); i++)
                for (int j = i + 1; j < arr.GetLength(0); j++)
                {
                    double temp = arr[i, j];
                    arr[i, j] = arr[j, i];
                    arr[j, i] = temp;
                }
            PrintArray(arr);
            #endregion

            #region Задание 1 (5 вариант)
            //2.5.	В двухмерном массиве целых чисел поменять местами столбцы, симметричные относительно середины массива (вертикальной линии).
            Console.WriteLine("\nИсходный массив:");
            int[,] arrInt = new int[size, size];
            Random rndInt = new Random();
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    arrInt[i, j] = rndInt.Next(-10, 10);
            PrintArray(arrInt);

            Console.WriteLine("\nЗадание 1");
            for (int j = 0; j < arr.GetLength(0) / 2; j++)
                for (int i = 0; i < arr.GetLength(0); i++)
                {
                    int temp = arrInt[i, j];
                    arrInt[i, j] = arrInt[i, arr.GetLength(0) - 1 - j];
                    arrInt[i, arr.GetLength(0) - 1 - j] = temp;
                }
            PrintArray(arrInt);
            #endregion

            #region Задание 2 (4 вариант)
            //3.4.	Составить программу, которая будет вводить строку в переменную String. 
            //Определить, сколько раз в строке встречается заданное слово.
            Console.WriteLine("\nЗадание 2");
            int count = 0;
            Console.Write("Введите строку: ");
            string str = Console.ReadLine();
            Console.Write("Введите слово: ");
            string word = Console.ReadLine();
            string[] masStr = str.Split(' ');
            foreach (string s in masStr)
                if (s == word) count++;
            Console.WriteLine($"Слово '{word}' содержится {count} раз в строке");
            #endregion

            #region Задание 2 (5 вариант)
            //3.5.	Строка, содержащая произвольный русский текст, состоит не более чем из 200 символов. 
            //Написать, какие буквы и сколько раз встречаются в этом тексте. 
            //Ответ должен приводиться в грамматически правильной форме: например: а - 25 раз, к - 3 раза и т. д.
            Console.WriteLine("\nЗадание 2");
            Console.Write("Введите текст: ");
            string text = Console.ReadLine();
            var alphabet = text.ToLower().Where(x => char.IsLetter(x)).GroupBy(x => x).OrderBy(x => x.Key);
            foreach (var ch in alphabet)
                Console.WriteLine(ch.Key + " - " + ch.Count() + " раз");
            #endregion

            #region Задание 3 (4 вариант)
            //4.4.	Задан текст. После каждой буквы «о» вставить сочетание «Ок».
            Console.WriteLine("\nЗадание 3");
            Console.Write("Введите текст: ");
            string Text = Console.ReadLine();
            Regex regex = new Regex("[оО]");
            Text = regex.Replace(Text, "оОк");
            Console.WriteLine("Текст после замены: " + Text);
            #endregion

            #region Задание 3 (5 вариант)
            //4.5.	Задан текст. Определить, является ли он текстом на русском языке.
            Console.WriteLine("\nЗадание 3");
            Console.Write("Введите текст: ");
            string textRus = Console.ReadLine();
            if(Regex.IsMatch(textRus, "[а-яА-Я]"))
                Console.WriteLine("Текст содержит русские буквы, значит текст на русском");
            else Console.WriteLine("Текст не содержит русские буквы, значит текст не на русском");
            #endregion
        }

        static void PrintArray(double[,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(0); j++)
                    Console.Write(Math.Round(arr[i, j], 2) + "\t");
                Console.WriteLine();
            }
        }

        static void PrintArray(int[,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(0); j++)
                    Console.Write(arr[i, j] + "\t");
                Console.WriteLine();
            }
        }
    }

    static class RandomExtension
    {
        /// <summary>
        /// Возвращает случайное число с плавающей запятой в диапазоне от minValue до maxValue.
        /// </summary>
        public static double NextFloat(this Random r, double minValue, double maxValue)
        {
            return minValue + r.NextDouble() * (maxValue - minValue);
        }

        /// <summary>
        /// Возвращает случайное число с плавающей запятой в диапазоне от 0 до maxValue.
        /// </summary>
        public static double NextFloat(this Random r, double maxValue)
        {
            return r.NextDouble() * maxValue;
        }
    }
}