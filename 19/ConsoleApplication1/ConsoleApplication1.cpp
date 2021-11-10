#include <iostream>
#include <vector>

void merge_sort(int* seq, int left, int right, long* inversions)
{
    if (left < right)
    {
        int middle = (left + right) / 2;

        merge_sort(seq, left, middle, inversions);
        merge_sort(seq, middle + 1, right, inversions);

        int* temp = new int[right - left + 1];
        int i = left;
        int j = middle + 1;
        int k = 0;

        while (i <= middle && j <= right)
        {
            if (seq[i] <= seq[j])
            {
                temp[k] = seq[i];
                i++;
            }
            else
            {
                temp[k] = seq[j];
                j++;
                *inversions += middle - i + 1;
            }
            k++;
        }

        while (i <= middle)
        {
            temp[k] = seq[i];
            k++;
            i++;
        }

        while (j <= right)
        {
            temp[k] = seq[j];
            k++;
            j++;
        }

        for (int i = left, k = 0; i <= right; i++, k++)
        {
            seq[i] = temp[k];
        }

        delete[] temp;
    }
}

int main()
{
    int N;
    std::cin >> N;

    int* sequence = new int[N];

    for (int i = 0; i < N; i++)
    {
        std::cin >> sequence[i];
    }

    long inversions = 0;
    merge_sort(sequence, 0, N - 1, &inversions);
    std::cout << inversions;

    return 0;
}