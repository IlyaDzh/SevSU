using System;

namespace ConsoleApp2
{
    class Exam : AExam, IVisitable
    {
        private int visits = 0;

        private string professor;
        public string Professor
        {
            get { return professor; }
            set { if (professor != "") professor = value; }
        }

        public Exam(string fullName, string date, int mark, string professor) : base(fullName, date, mark)
        {
            this.professor = professor;
        }

        new public void Print()
        {
            Console.WriteLine($"Студент: {FullName} | Дата: {Date} | Оценка: {Mark}");
            base.PrintQuestions();
        }

        public override void PrintInfo()
        {
            Console.WriteLine($"Преподователь: {professor} | Посещений: {visits}");
        }

        public void Visit(int visits)
        {
            this.visits = visits;
        }

        public int GetVisits()
        {
            return visits;
        }

    }
}