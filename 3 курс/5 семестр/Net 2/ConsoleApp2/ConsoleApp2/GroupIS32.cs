using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class GroupIS32 : Exam
    {
        public GroupIS32():base()
        { }

        public GroupIS32(string fio, int date, int score, string questions) : base()
        {
            this.fio = fio;
            this.date = date;
            this.date = score;
            this.questions = questions;
            if (score >= 90) this.setMark(Mark.Excellent);
            if (score >= 75 && score < 90) this.setMark(Mark.Good);
            if (score >= 60 && score < 75) this.setMark(Mark.Satisfactory);
            if (score < 60) this.setMark(Mark.Bad);
        }

        public void PrintAll()
        {
            Console.WriteLine("FIO: " + fio);
            Console.WriteLine("Date: " + date);
            Console.WriteLine("Score: " + score);
            Console.WriteLine("Mark: " + mark);
            Console.WriteLine("Questions: " + questions);
        }
    }
}