#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
string s;

int check(int idx)
{
	int a, b;
	a = b = s.size() * 2 - 1;
	for (int i = 1;; i++)
	{
		if (idx + i >= s.size() || idx < i)
		{
			a =  idx * 2 + 1;
			break;
		}
		if (s[idx - i] != s[idx + i])
		{
			break;
		}
	}
	for (int i = 0;; i++)
	{
		if (idx + i >= s.size())
		{
			b = idx * 2;
			break;
		}
		if (idx < i + 1)
		{
			break;
		}
		if (s[idx - i - 1] != s[idx + i])
		{
			break;
		}
	}
	return a < b ? a : b;
}

int main()
{
	cin >> s;
	int answer = s.size() * 2 - 1;
	int mid = s.size() / 2;
	for (int i = 0; i <= s.size() / 2; i++)
	{
		if (s.size() + i > answer)
		{
			break;
		}
		int b = check(mid + i);
		if (answer > b)
		{
			answer = b;
		}
	}
	cout << answer << endl;
}