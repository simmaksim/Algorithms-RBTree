#include <iostream>

void Sort_and_Count(int* mainArr, int size);
int counter = 0;
int main()
{
	int n;
	std::cin >> n;
	int number;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	Sort_and_Count(arr, n);

	std::cout << counter;
}

void Sort_and_Count(int* arr, int size)
{
	if (size == 1)
	{
		return;
	}

	int pol = size / 2;
	int* A = new int[pol];
	for (int i = 0; i < pol; i++)
	{
		A[i] = arr[i];
	}

	int pol2 = size - pol;
	int* B = new int[pol2];
	for (int i = pol; i < size; i++)
	{
		B[i - pol] = arr[i];
	}

	Sort_and_Count(A, pol);
	Sort_and_Count(B, pol2);
	int first = 0, second = 0;

	while (first < pol && second < pol2)
	{
		if (A[first] <= B[second])
		{
			arr[first + second] = A[first];
			first++;
		}
		else
		{
			counter +=(pol - first);
			arr[first + second] = B[second];
			second++;
		}
	}
}