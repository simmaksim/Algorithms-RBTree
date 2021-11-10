#define _CRT_SECURE_NO_WARNINGS
#include <fstream>;
#include <vector>
#include <iostream>
#include <algorithm>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	std::ofstream fout("output.txt");
	int n;
	std::cin >> n;
	std::vector<long long> values(n);
	long long x;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		values[i] = x;
	}
	std::sort(values.begin(), values.end());
	long long result = values[0] * values[1];
	long long possibleResult = values[n - 1] * values[n - 2];
	if (result > possibleResult) {
		fout << result;
	}
	else {
		fout << possibleResult;
	}
	return 0;
}