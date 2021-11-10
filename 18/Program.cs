using System;

namespace Year
{
    class Vis
    {
        static void Main(string[] args)
        {
            bool flag;
            int year = Convert.ToInt32(Console.ReadLine());
            flag = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;
            //(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? flag = true : flag = false;
            if (flag)
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
        }
    }
}
