#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
struct location
{
	int x;
	int y;
	location(int i, int j)
	{
		x = i;
		y = j;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	std::ofstream fout("output.txt");
	int n, m, i, j;
	std::cin >> n >> m >> i >> j;
	std::vector<std::vector<int> > v(n + 1, std::vector<int>(m + 1, NULL));
	v[1][1] = 0;
	std::queue<location> q;
	q.push(location(1, 1));
	while (!q.empty())
	{

		location tmp = q.front();
		q.pop();
		for (int i = -2; i < 3; i++)
		{
			for (int j = -2; j < 3; j++)
			{
				location tmpLocation = location(tmp.x + i, tmp.y + j);
				if (tmpLocation.x <= n && tmpLocation.y <= m)
				{
					if ((abs(i) + abs(j)) == 3 && tmpLocation.x >= 1 && tmpLocation.y >= 1)
					{
						if (v[tmpLocation.x][tmpLocation.y] == NULL)
						{
							v[tmpLocation.x][tmpLocation.y] = v[tmp.x][tmp.y] + 1;
							q.push(tmpLocation);
						}
					}
				}

			}
		}
	}


	if (v[i][j] == NULL)
		fout << "NEVAR";
	else
		fout << v[i][j];

	return 0;
}