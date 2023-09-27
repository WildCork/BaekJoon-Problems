#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<int> s;

int check(int n)
{
	int answer = 1;
	for (int i = 1; i < 5; i++)
	{
		if (s.find(n + i) != s.end())
		{
			answer++;
		}
	}
	return answer;
}

int main()
{
	int n, dummy;
	int answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> dummy;
		s.insert(dummy);
	}
	for (auto it = s.begin(); it != s.end(); it++)
	{
		int c = check(*it);
		if (answer < c)
		{
			answer = c;
		}
	}
	cout << 5 - answer;
}