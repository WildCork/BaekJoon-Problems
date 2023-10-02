#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int n, m;
int nn[1001][1001];

vector<int> visited;

void dfs(int i, int cost)
{
	if (visited[i] >= 0 && cost > visited[i])
	{
		return;
	}
	visited[i] = cost;
	for (int j = 1; j < n + 1; j++)
	{
		if (nn[i][j])
		{
			dfs(j, cost + nn[i][j]);
		}
	}
}

int main()
{
	cin >> n >> m;
	visited.resize(n + 1);
	int a, b, c;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		nn[a][b] = c;
		nn[b][a] = c;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		fill(visited.begin(), visited.end(), -1);
		dfs(a, 0);
		cout << visited[b] << endl;
	}
}