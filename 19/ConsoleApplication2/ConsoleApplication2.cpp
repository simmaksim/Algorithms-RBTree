#include <iostream>

void Sort_and_Count(int* arr, int start, int size, int* count)
{
    if (start < size)
    {
        int pol = (start + size) / 2;

        Sort_and_Count(arr, start, pol, count);
        Sort_and_Count(arr, pol + 1, size, count);

        int* A = new int[size - start + 1];
        int j = pol + 1;
        int tmp = 0;

        while (start <= pol && j <= size)
        {
            if (arr[start] <= arr[j])
            {
                A[tmp] = arr[start];
                start++;
            }
            else
            {
                A[tmp] = arr[j];
                j++;
                *count += pol - start + 1;
            }
            tmp++;
        }

        while (start <= pol)
        {
            A[tmp] = arr[start];
            tmp++;
            start++;
        }

        while (j <= size)
        {
            A[tmp] = arr[j];
            tmp++;
            j++;
        }

        for (int i = start; i <= size; i++)
        {
            int j = 0;
            arr[i] = A[j];
            j++;
        }
    }
}

int main()
{
    int n;
    std::cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int counter = 0;
    Sort_and_Count(arr, 0, n - 1, &counter);
    std::cout << counter;

    return 0;
}