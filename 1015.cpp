#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	set<int> k;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		k.insert(v[i]);
	}
	vector<int> kk;
	for (auto it = k.begin(); it != k.end(); it++)
	{
		kk.push_back(*it);
	}
	vector<int> answer(n);
	int idx = 0;
	for (int i = 0; i < kk.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == kk[i])
			{
				answer[j] = idx++;
			}
		}
	}
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
}