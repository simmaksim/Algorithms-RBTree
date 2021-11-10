#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <vector>

const int m = 1000000007;

std::vector<std::vector<long long>> mult(std::vector<std::vector<long long>> first, std::vector<std::vector<long long>> sec);
std::vector<std::vector<long long>> binPower(std::vector<std::vector<long long>> first, int count);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    std::ofstream fout("output.txt");
    int N, M;
    std::cin >> N >> M;

    int U, V, L;
    std::cin >> U >> V >> L;

    std::vector<std::vector<long long>> arr(N, std::vector<long long>(N, 0));
    for (int i = 0; i < M; i++) {
        int A, B;
        std::cin >> A >> B;
        if (A == B)
            arr[A-1][B-1] += 2;
        else {
            arr[A-1][B-1]++;
            arr[B-1][A-1]++;
        }
    }

    arr = binPower(arr, L);

    fout << arr[U - 1][V - 1];
}

std::vector<std::vector<long long>> mult(std::vector<std::vector<long long>> first, std::vector<std::vector<long long>> sec) {
    int size = (int)first.size();
    std::vector<std::vector<long long>> tmp(size, std::vector<long long>(size, 0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++)
                tmp[i][j] = (tmp[i][j] + first[i][k] * sec[k][j] % m) % m;
        }
    }
    return tmp;
}

std::vector<std::vector<long long>> binPower(std::vector<std::vector<long long>> first, int count) {
    int size = (int)first.size();
    std::vector<std::vector<long long>> tmp(size, std::vector<long long>(size, 0));
    for (int i = 0; i < size; i++)
        tmp[i][i] = 1;

    while (count)
        if (count % 2 != 1) {
            first = mult(first, first);
            count /= 2;
        }
        else {
            tmp = mult(tmp, first);
            count--;
        }
    return tmp;
}