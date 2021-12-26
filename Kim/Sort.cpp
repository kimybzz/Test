#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include "Sort.h"
using namespace std;

// 선택정렬 : 항상 O(N의제곱)
// 삽입정렬 : 최대 O(N의제곱) / 최소 O(N)
// 퀵정렬	: 항상 O(N x LogN)
// 계수정렬 : 항상 O(N + K)  <-- 여기서 K는 최대값

// 계수 정렬 (0 이상의 정수로 구성되어 있으며, 최대값이 너무 크지 않을때 사용하면 유리)
Sort::Sort()
{
	int arr[] = { 7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2 };

	int max = 10;
	int* map = new int[max] {0, };

	for (auto val : arr)
		++map[val];

	for (int i = 0; i < max; ++i)
	{
		for (int k = 0; k < map[i]; ++k)
		{
			cout << i << " ";
		}
	}

	delete[] map;
}