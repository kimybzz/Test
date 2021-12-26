#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include "Basic.h"

using namespace std; //

bool compare(string &a, string &b)
{
	return a.compare(b) > 0;
}

Basic::Basic()
{
	int sum[10] = { 1, 0 };
	for (auto a : sum)
		cout << a << endl;
	return;

	vector<int> v = { 2, 4, 3 };
	priority_queue<int, vector<int>, greater<int>> que(v.begin(), v.end());
	cout << que.top() << endl;
	return;

	vector<string> vec = { "123", "1225" };
	sort(vec.begin(), vec.end(), [](string &a, string &b) { return a.compare(b) < 0; });

	greater<string> pred;
	sort(vec.begin(), vec.end(), pred);

	for (string s : vec)
		cout << s << endl;
	return;

	vector<string> m = { "0", "1", "2" };
	for (auto vec_it = m.begin(); vec_it != m.end(); ++vec_it)
	{
		if (*vec_it == "2")
		{
			auto it = next(vec_it, -1);
			cout << *it << endl;
		}
	}

}

