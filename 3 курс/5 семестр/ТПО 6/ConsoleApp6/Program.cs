using System;
using System.Threading;

namespace ConsoleApp6
{
    class Program
    {
        static void Main(string[] args)
        {
            Student student = new Student("Долженко Илья Андреевич", 32, "ТПО", 98, DateTime.Now);
            Console.WriteLine($"Студент: {student.getName()}, Группа: {student.getGroup()}");
            Console.WriteLine($"Предмет: {student.getSubject()}, Оценка: {student.getMark()}, Дата: {student.getTime()}");

            Console.WriteLine("----------------------------------------------------");

            Student student2 = new Student("Волобуев Юрий Сергеевич", 32, "ТПО", 65, DateTime.Now);
            Console.WriteLine($"Студент: {student2.getName()}, Группа: {student2.getGroup()}");
            Console.WriteLine($"Предмет: {student2.getSubject()}, Оценка: {student2.getMark()}, Дата: {student2.getTime()}");

            Console.ReadKey();
        }
    }

    public class Student
    {
        private string name;
        private int group;
        private int mark;
        private string subject;
        private DateTime time;

        public Student(string name, int group, string subject, int mark, DateTime time)
        {
            this.group = group;
            this.name = name;
            this.subject = subject;
            this.mark = mark;
            this.time = time;
        }

        public string getName()
        {
            return name;
        }

        public int getGroup()
        {
            return group;
        }

        public int getMark()
        {
            return mark;
        }

        public string getSubject()
        {
            return subject;
        }

        public DateTime getTime()
        {
            return time;
        }
    }
}