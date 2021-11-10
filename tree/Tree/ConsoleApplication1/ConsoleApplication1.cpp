#include <chrono>
#include <math.h>
#include <ctime>
#include <iostream>
#include "Tree.h"

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	Tree<int> tree;
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < 11; i++)
		tree.insert(i);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / pow(10, 9);
	cout << "Time: " << duration << endl;
	tree.deleteByValue(4);
	tree.searchIter(5);
	tree.printLevelOrder();
	tree.printInOrder();
}