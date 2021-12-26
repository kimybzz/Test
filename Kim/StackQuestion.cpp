#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "StackQuestion.h"

using namespace std;


void PrintResult(string& text, int array[])
{
	cout << "Quest = " + text << endl;

	for (int i = 0; i < text.length(); ++i)
	{
		if (i < text.length() - 1)
			cout << array[i] << ",";
		else
			cout << array[i];
	}

	cout << endl << endl;
}

// array : text ������ ��ŭ �迭 ����
void CalcResult(string& text, int array[])
{
	stack<int> stack;
	int order = 1;

	for (int i = 0; i < text.length(); ++i)
	{
		if (text[i] == '(')
		{
			// '(' �� ���° �������� �׾Ƶд�
			stack.push(i);
		}
		else
		{
			// '(' �� �ִ� �ڸ��� �������� �ִ´�
			int left = stack.top();
			array[left] = order;

			// ')' �� �ִ� �ڸ��� �������� �ִ´�
			array[i] = order;

			// ������ ����
			++order;

			// top�� �ִ°� �����Ѵ�.
			stack.pop();
		}
	}
}

void SetQuest(string text)
{
	int* array = new int[text.length()];
	CalcResult(text, array);
	PrintResult(text, array);
}

StackQuestion::StackQuestion()
{
	SetQuest("(()())");

	SetQuest("()()");

	SetQuest("(()())(())");
}
