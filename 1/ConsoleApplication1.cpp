#define _CRT_SECURE_NO_WARNINGS
#include <fstream>;
#include <vector>
#include <iostream>
#include <algorithm>
int findSet(int i, std::vector<int>& dsu) {
	std::vector<int> compression;
	while (dsu[i] > 0) {
		compression.push_back(i);
		i = dsu[i];
	}
	if (compression.size() > 1) {
		for (size_t k = 0; k < compression.size(); k++)
		{
			dsu[compression[k]] = i;
		}
	}
	return i;
}
bool Union(int set1, int set2, std::vector<int>& dsu) {
	if (set1 == set2) {
		return false;
	}
	if (dsu[set1] < dsu[set2]) {
		dsu[set1] += dsu[set2];
		dsu[set2] = set1;
	}
	else {
		dsu[set2] += dsu[set1];
		dsu[set1] = set2;
	}
	return true;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	std::ofstream fout("output.txt");

	int n;
	std::cin >> n;
	std::vector<int> dsu(n + 1, -1);
	int k;
	std::cin >> k;
	int first;
	int second;
	int set1;
	int set2;
	for (int i = 0; i < k; i++)
	{
		std::cin >> first;
		std::cin >> second;
		set1 = findSet(first, dsu);
		set2 = findSet(second, dsu);
		if (Union(set1, set2, dsu)) {
			n--;
		}
	}
	fout << n - 1;
	return 0;
}