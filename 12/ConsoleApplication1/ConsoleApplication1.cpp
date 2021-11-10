#define _CRT_SECURE_NO_WARNINGS
#include <fstream>;
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	std::ofstream fout("output.txt");

	long long  n;
	std::cin >> n;
	if (n % 10 == 0) {
		fout << "NO";
	}
	else {
		fout << n % 10;
	}
	return 0;
}