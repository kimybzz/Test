#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include "Sort.h"
using namespace std;

// �������� : �׻� O(N������)
// �������� : �ִ� O(N������) / �ּ� O(N)
// ������	: �׻� O(N x LogN)
// ������� : �׻� O(N + K)  <-- ���⼭ K�� �ִ밪

// ��� ���� (0 �̻��� ������ �����Ǿ� ������, �ִ밪�� �ʹ� ũ�� ������ ����ϸ� ����)
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