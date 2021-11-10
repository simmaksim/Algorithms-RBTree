using System;


namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string tmp = Console.ReadLine();
            int surce = Convert.ToInt32(tmp);
            int[] nums = new int[tmp.Length];
            
            for (int i = 0; i < tmp.Length; i++)
            {
                nums[i] = Convert.ToInt32(tmp[i]);
            }

        }
    }
}
