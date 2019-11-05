using System;

namespace ConsoleApp2
{
    abstract class AExam
    {
        private string fullName;
        public string FullName
        {
            get { return fullName; }
            set { if (fullName == null) { fullName = value; } else { throw new ValueException(FieldType.Name); } }
        }

        private string date;
        public string Date
        {
            get { return date; }
            set { if (date == null) { date = value; } else { throw new ValueException(FieldType.Date); } }
        }

        public int Mark { get; }
        public int QuestionsCount { get; private set; } = 0;

        const int questionsMaxCount = 8;
        private string[] questions = new string[questionsMaxCount];
        public string this[int i]
        {
            get
            {
                if (i >= 0 && i <= QuestionsCount) { return questions[i]; }
                else { throw new ValueException(FieldType.Questions); }
            }
            set
            {
                if (i == QuestionsCount) { questions[i] = value; QuestionsCount++; }
                else if (i >= 0 && i <= QuestionsCount) { questions[i] = value; }
                else { throw new ValueException(FieldType.Questions); }
            }
        }

        public AExam(string fullName, string date, int mark)
        {
            this.fullName = fullName;
            this.date = date;
            this.Mark = mark;
        }

        public virtual void Print()
        {
            Console.WriteLine($"Студент: {fullName} | Дата: {date} | Оценка: {Mark}");
        }

        public void PrintQuestions()
        {
            for (int i = 0; i < QuestionsCount; i++)
            {
                Console.WriteLine($"Вопрос {i + 1}: {this[i]}");
            }
        }

        public abstract void PrintInfo();
    }
}