using System;
using System.Linq;


namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            bool flag = true;
            for (int i = 0, j = str.Length - 1; i <= j; i++)
            {
                if (str[i] != str[j])
                {
                    Console.WriteLine(str.Length);
                    return;
                }
                if (flag && (str[i] != str.First()))
                    flag = false;
                j++;
            }
            if (!flag)
                Console.WriteLine(str.Length - 1);
            else
                Console.WriteLine(-1);
        }
    }
}
