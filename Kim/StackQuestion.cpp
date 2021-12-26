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

// array : text 사이즈 만큼 배열 선언
void CalcResult(string& text, int array[])
{
	stack<int> stack;
	int order = 1;

	for (int i = 0; i < text.length(); ++i)
	{
		if (text[i] == '(')
		{
			// '(' 가 몇번째 글자인지 쌓아둔다
			stack.push(i);
		}
		else
		{
			// '(' 가 있는 자리에 순서값을 넣는다
			int left = stack.top();
			array[left] = order;

			// ')' 가 있는 자리에 순서값을 넣는다
			array[i] = order;

			// 순서값 증가
			++order;

			// top에 있는걸 삭제한다.
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
