#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

std::string swap(std::string str, int x, int y);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    std::ofstream fout("output.txt");
    std::string str;
    std::cin >> str;
    bool flg1 = false, flg2 = false;
    int pointer = -1;
    for (int i = str.length() - 2; i >= 0; i--)
    {
        for (int j = str.length() - 1; j > i; j--)
        {
            if (str[i]<str[j])
            {
                str = swap(str, i, j);
                pointer = i + 1;
                flg1 = true;
                break;
            }           
        }
        if (flg1)
        {
            while (!flg2)
            {
                flg2 = true;
                for (int i = pointer; i < str.length()-1; i++)
                {
                    if (str[i] > str[i+1])
                    {
                        flg2 = false;
                        str = swap(str, i, i + 1);
                    }
                }
            }
            break;
        }
    }
    if (flg1)
    {
        fout << str;
        return 0;
    }
    fout << -1;
    return 0;
}

std::string swap(std::string str, int x, int y) {
    char tmp = str[x];
    str[x] = str[y];
    str[y] = tmp;
    return str;
}