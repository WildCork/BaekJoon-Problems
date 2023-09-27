#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, score, p;
	cin >> n >> score >> p;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	v.push_back(score);
	sort(v.begin(), v.end(), greater<int>());
	if (n == p && score == v.back())
	{
		cout << -1;
	}
	else
	{
		for (int i = 0; i < n + 1; i++)
		{
			if (v[i] == score)
			{
				cout << i + 1;
				return 0;
			}
		}
	}
}