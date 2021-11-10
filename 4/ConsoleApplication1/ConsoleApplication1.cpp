#include <iostream>
#include <vector>
#include <queue>
using namespace std;
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
	int n, m, i, j;
	cin >> n >> m >> i >> j;
	vector<vector<int> > v(n + 1, vector<int>(m + 1, NULL));
	v[1][1] = 0;
	queue<location> q;
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
		cout << "NEVAR";
	else
		cout << v[i][j];

	return 0;
}