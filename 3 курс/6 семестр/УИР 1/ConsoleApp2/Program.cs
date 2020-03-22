using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            var avltree = new AVLTree<int>();
            avltree.Insert(1);
            avltree.Insert(3);
            avltree.Insert(9);
            avltree.Insert(32);
            avltree.Insert(24);
            avltree.Insert(22);
            avltree.Insert(44);
            avltree.Insert(33);
            avltree.Insert(86);
            avltree.Insert(5);

            avltree.PrintDot();

            Console.ReadLine();
        }
    }
}