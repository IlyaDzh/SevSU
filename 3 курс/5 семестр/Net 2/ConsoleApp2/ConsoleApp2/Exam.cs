using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    public enum Mark
    {
        Excellent,
        Good,
        Satisfactory,
        Bad
    }

    public abstract class Exam
    {
        protected string fio { get; set; }
        protected int date { get; set; }
        protected int score { get; set; }
        protected Mark mark { get; set; }
        protected string questions { get; set; }

        public void setMark(Mark mark)
        {
            this.mark = mark;
        }

        public virtual void setAll()
        {
            try
            {
                Console.Write("FIO: ");
                fio = Console.ReadLine();

                Console.Write("Date: ");
                date = Convert.ToInt32(Console.ReadLine());

                Console.Write("Score: ");
                score = Convert.ToInt32(Console.ReadLine());

                Console.Write("Questions: ");
                questions = Console.ReadLine();
            }
            catch (Exception)
            {
                Console.WriteLine("\nExeption. Retry enter data again\n");
                setAll();
            }

        }
    }
}
