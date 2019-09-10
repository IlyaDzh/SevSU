using System;
using System.Text.RegularExpressions;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            //2.4.	В двухмерном массиве вещественных чисел поменять местами строки и столбцы с одинаковыми номерами.
            Console.WriteLine("Задание 1");
            Console.Write("Введите размерность матрицы: ");
            int size = Int32.Parse(Console.ReadLine());

            Console.WriteLine("Исходный массив:");
            double[,] arr = new double[size, size];
            Random rnd = new Random();
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    arr[i, j] = rnd.NextFloat(-10, 10);
            PrintArray(arr);

            Console.WriteLine("Результат:");
            for (int i = 0, length = arr.GetLength(0); i < length; i++)
                for (int j = i + 1; j < length; j++)
                {
                    double temp = arr[i, j];
                    arr[i, j] = arr[j, i];
                    arr[j, i] = temp;
                }
            PrintArray(arr);

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

            //4.4.	Задан текст. После каждой буквы «о» вставить сочетание «Ок».
            Console.WriteLine("\nЗадание 3");
            Console.Write("Введите текст: ");
            string Text = Console.ReadLine();
            Regex regex = new Regex("[оО]");
            Text = regex.Replace(Text, "оОк");
            Console.WriteLine("Текст после замены: " + Text);
        }

        static void PrintArray(double[,] arr)
        {
            for (int i = 0, length = arr.GetLength(0); i < length; i++)
            {
                for (int j = 0; j < length; j++)
                    Console.Write(Math.Round(arr[i, j], 2) + "\t");
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
    }
}