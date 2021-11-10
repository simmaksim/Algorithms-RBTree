using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            int k;
            int m = 1000000007;
            int[] mas = spl(Console.ReadLine()).Select(Int32.Parse).ToArray();
            n = mas[0];
            k = mas[1];
            long[] arr = spl(Console.ReadLine()).Select(Int64.Parse).ToArray();
            Array.Sort(arr);
            long res = 1;
            if (arr[0] >= 0)
            {
                for (int i = 0; i < k; i++)
                {
                    res = ((res % m) * (arr[n - 1 - i] % m)) % m;
                }
            }
            else if (arr[n - 1] <= 0)
            {
                if (k % 2 == 0)
                {
                    for (int i = 0; i < k; i++)
                    {
                        res = ((res % m) * (arr[i] % m)) % m;
                    }
                }
                else
                {
                    for (int i = 0; i < k; i++)
                    {
                        res = ((res % m) * (arr[n - 1 - i] % m)) % m;
                    }
                }
            }
            else
            {
                int start = 0;
                int end = n - 1;
                for (; k > 0;)
                {
                    if (k > 1 && (arr[start] * arr[start + 1] >= arr[end] * arr[end - 1]))
                    {
                        res = ((res % m) * ((arr[start] % m) * (arr[start + 1] % m) % m) % m);
                        start += 2;
                        k -= 2;
                    }
                    else
                    {
                        res = ((res % m) * (arr[end] % m) % m);
                        end--;
                        k--;
                    }
                }
            }
            res = (res + m) % m;
            Console.WriteLine(res);
        }
        static string[] spl(string text)
        {
            int i;
            int lastI = 0;
            List<string> list = new List<string>();
            while ((i = text.IndexOf(' ', lastI)) != -1)
            {
                list.Add(text.Substring(lastI, i - lastI));
                lastI = ++i;
            }
            list.Add(text.Substring(lastI));
            return list.ToArray();
        }
    }
}
