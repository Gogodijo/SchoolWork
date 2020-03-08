using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Diskreetti01
{
    public class PublicCounter
    {
        private static int counter;

        public static int Counter { get => counter; set => counter = value; }
    }
    class Program
    {

        static void Main(string[] args)
        {
            int luku = 0;
            Console.WriteLine("Anna positiivinen kokonaisluku. Ohjelma laskee suhteelliset alkuluvut ja laskee niiden lukumäärän");
            try
            {
                 luku = int.Parse(Console.ReadLine());
                if(luku <= 0)
                {
                    throw new Exception();
                }
                int[] array = ZLengts(luku);
                PrintArray(array);
                Console.WriteLine(" \nSuhteellisten alkulukujen lukumäärä: {0}", array.Count());
                
            }
             catch(Exception e)
            {
                Console.WriteLine("Virhe!" + e);
            }
            int a = PublicCounter.Counter;
            Console.WriteLine("Syttejä tehtiin: {0} kpl", a);
        }
        static int[] ZLengts(int number)
        {
            List<int> list = new List<int>();
            for (int i = 1; i < number; ++i)
            {
                if (GCDRecursive(number, i) == 1)
                {
                    list.Add(i);
                }
            }

            return list.ToArray();
        }
        static int GCDRecursive(int a, int b)
        {
            PublicCounter.Counter = PublicCounter.Counter + 1;
            if (a == 0)
            {
                return b;
            }
            if (b == 0)
            {
                return a;
            }
            if (a > b)
            {
                return GCDRecursive(a % b, b);
            }
            else
            {
                return GCDRecursive(a, b % a);
            }
        }
        static void PrintArray(int[] arr)
        {
            foreach (var item in arr)
            {
                Console.Write(item + " ");
            }
        }

    }
}
