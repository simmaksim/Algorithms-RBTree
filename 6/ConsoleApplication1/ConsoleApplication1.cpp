#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
int main()
{
    int n;
    std::cin >> n;
    int m, minimal, index;
    int nach, konch, tmp;
    std::cin >> m;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        arr[a-1][b-1] = arr[b-1][a-1] = c;
    }
    std::cin >> nach;
    std::cin >> konch;
    bool* visited = new bool[n];
    int* distance = new int [n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT32_MAX;
    }
    distance[nach - 1] = 0;
    do
    {
        index = INT32_MAX;
        minimal = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] < minimal)
            {
                minimal = distance[i];
                index = i;
            }
        }
        if (index != INT32_MAX)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[index][i] > 0)
                {
                    tmp = minimal + arr[index][i];
                    if (tmp<distance[i])
                    {
                        distance[i] = tmp;
                    }
                }
            }
            visited[index] = true;
        }
    }     while (index < INT32_MAX);
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    std::cout << distance[konch - 1];
    delete[] arr;
    delete[] distance;
    delete[] visited;
   
    
    return 0;
}
