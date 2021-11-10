using System;
using System.Linq;


namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            const int number = 1087388483;
            int n = Convert.ToInt32(Console.ReadLine());
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = Convert.ToInt32(Console.ReadLine());
            if ((arr.Contains(1021) && arr.Contains(1031) && arr.Contains(1033)) || ((arr.Contains(1021) && arr.Contains(1031 * 1033)) || (arr.Contains(1031) && arr.Contains(1021 * 1033)) || (arr.Contains(1033) && arr.Contains(1021 * 1031))) || (arr.Contains(number)))
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
        }
    }
}