using System;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static int[] input(string str)
        {
            return str.Split().Select(x => int.Parse(x)).ToArray();
        }
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            int[] arr = new int[6];
            arr = input(str);
            int X1 = arr[2], Y1 = arr[3], X2 = arr[4], Y2 = arr[5];
            int resX = X1 - X2;
            int resY = Y1 - Y2;
            bool flag = Math.Abs(resX) != Math.Abs(resY) ? true : false;
            if (flag)
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
        }
    }
}
