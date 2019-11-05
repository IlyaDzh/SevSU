using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Exam exam1 = new Exam("Долженко Илья Андреевич", "20.12.2019", 5, "Дрозин А.Ю.");
            exam1[0] = "Что такое массив?";
            exam1[1] = "Виды массивов";
            exam1[2] = "Добавление элементов в массив";
            exam1[3] = "Удаление элементов в массиве";
            exam1.Print();
            exam1.Visit(new Random().Next(25));
            exam1.PrintInfo();

            try
            {
                exam1.FullName = "Юра";
            }
            catch (ValueException ex)
            {
                Console.WriteLine($"Попытка изменить поле ФИО. Ошибка: {ex.Message}");
            }

            Console.WriteLine("---------------------------------------");

            Exam exam2 = new Exam("Волобуев Юра Сергеевич", "22.12.2019", 4, "Дрозин А.Ю.");
            exam2[0] = "Что такое HTML?";
            exam2[1] = "Что такое CSS?";
            exam2[2] = "Как добавить событие?";
            exam2.Print();
            exam2.Visit(new Random().Next(11));
            exam2.PrintInfo();

            Console.WriteLine("\nНажмите любую клавишу...");
            Console.ReadKey();
        }
    }
}