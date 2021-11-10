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
            int n = Convert.ToInt32(Console.ReadLine());
            string str = Console.ReadLine();
            int[] arr = new int[n];
            arr = input(str);
            int counter = 0;
            int max = arr[0];
            for (int i = 1; i < n; i++)
            {
                if (arr[i] > max)
                {
                    counter += (arr[i] - max);
                    max = arr[i];
                }
                else if (arr[i] < arr[0])
                    counter += (arr[0] - arr[i]);
                arr[0] = arr[i];            
            }
            Console.WriteLine(counter);
        }

    }
}
