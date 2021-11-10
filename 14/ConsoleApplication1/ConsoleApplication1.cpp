#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

long count = 0;

void Merge(int* arr, int n);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	std::ofstream fout("output.txt");
	int n;
	std::cin >> n;
	int* arr = new int[n];
	for (int* i = arr; i != arr + n; i++)
		std::cin >> *i;
	Merge(arr, n);
	fout << count;
	delete arr;
}

void Merge(int* arr, int n)
{
	if (n == 1)
		return;
	int firstHalf = n / 2;
	int* firstArr = new int[firstHalf];
	for (int i = 0; i < firstHalf; i++)
		firstArr[i] = arr[i];
	int secHalf = n - n / 2;
	int* secArr = new int[secHalf];
	for (int i = n / 2; i < n; i++)
		secArr[i - n / 2] = arr[i];
	Merge(firstArr, firstHalf);
	Merge(secArr, secHalf);
	int first = 0, second = 0;
	while (firstHalf > first && secHalf > second)
	{
		if (firstArr[first] <= secArr[second])
		{
			arr[first + second] = firstArr[first];
			first++;
		}
		else
		{
			count += (long)(firstHalf - first);
			arr[first + second] = secArr[second];
			second++;
		}
	}
	while (first < firstHalf)
	{
		arr[first + second] = firstArr[first];
		first++;
	}
	while (second < secHalf)
	{
		arr[first + second] = secArr[second];
		second++;
	}
	delete[] firstArr;
	delete[] secArr;
}