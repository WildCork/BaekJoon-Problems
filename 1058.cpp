#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

vector<bool> visited;
vector<string> v;

int n;
int answer = 0;

void dfs(int idx, int d)
{
	if (visited[idx] || d > 2)
	{
		return;
	}
	visited[idx] = true;
	for (int i = 0; i < n; i++)
	{
		if (v[idx][i] == 'Y')
		{
			dfs(i, d + 1);
		}
	}
}

int main()
{
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	visited.resize(n);
	for (int i = 0; i < n; i++)
	{
		dfs(i, 0);
		int n = accumulate(visited.begin(), visited.end(), 0) - 1;
		if (answer < n)
		{
			answer = n;
		}
		fill(visited.begin(), visited.end(), false);
	}
	cout << answer;
}