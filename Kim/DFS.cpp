#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include "DFS.h"
using namespace std; // Branch Test


bool** arrChecked;

void init_arr(int m, int n)
{
    arrChecked = new bool* [m];
    for (int i = 0; i < m; ++i)
    {
        arrChecked[i] = new bool[n];
        memset(arrChecked[i], false, n);
    }

}
void delete_arr(int m)
{
    for (int i = 0; i < m; ++i)
        delete[] arrChecked[i];
    delete[] arrChecked;
}

// Àç±ÍÇÔ¼ö ¹æ½Ä (DFS : ±íÀÌ ¿ì¼± Å½»ö)
void get_area_size1(int areaType, int x, int y, int n, int m, const vector<vector<int>>& picture, int& areaCount)
{
    cout << "Recursion : " << y << ", " << x << endl;

    if (x < 0 || x >= n || y < 0 || y >= m)
        return;

    if (arrChecked[y][x])
        return;

    if (picture[y][x] == areaType)
    {
        arrChecked[y][x] = true;
        ++areaCount;

        get_area_size1(areaType, x + 1, y, n, m, picture, areaCount);
        get_area_size1(areaType, x - 1, y, n, m, picture, areaCount);
        get_area_size1(areaType, x, y + 1, n, m, picture, areaCount);
        get_area_size1(areaType, x, y - 1, n, m, picture, areaCount);
    }
}


// Stack ¹æ½Ä (DFS : ±íÀÌ ¿ì¼± Å½»ö)
struct Pos
{
    int x, y;

    Pos(int posX, int posY)
    {
        x = posX;
        y = posY;
    }
};
void get_area_size2(int areaType, Pos pos, int n, int m, const vector<vector<int>>& picture, int& areaCount)
{
    stack<Pos> st;
    st.push(pos);

    while ( !st.empty())
    {
        Pos p = st.top();
        st.pop();

        cout << "Stack : " << p.y << ", " << p.x << endl;

        if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m)
            continue;

        if (arrChecked[p.y][p.x])
            continue;

        if (picture[p.y][p.x] == areaType)
        {
            arrChecked[p.y][p.x] = true;
            ++areaCount;

            st.push(Pos(p.x, p.y - 1));
            st.push(Pos(p.x, p.y + 1));
            st.push(Pos(p.x - 1, p.y));
            st.push(Pos(p.x + 1, p.y));
        }
    }
}

// Queue ¹æ½Ä (BFS : ³Êºñ ¿ì¼± Å½»ö)
void get_area_size3(int areaType, Pos pos, int n, int m, const vector<vector<int>>& picture, int& areaCount)
{
    queue<Pos> que;
    que.push(pos);

    while (!que.empty())
    {
        Pos p = que.front();
        que.pop();

        cout << "queue : " << p.y << ", " << p.x << endl;

        if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m)
            continue;

        if (arrChecked[p.y][p.x])
            continue;

        if (picture[p.y][p.x] == areaType)
        {
            arrChecked[p.y][p.x] = true;
            ++areaCount;

            que.push(Pos(p.x + 1, p.y));
            que.push(Pos(p.x - 1, p.y));
            que.push(Pos(p.x, p.y + 1));
            que.push(Pos(p.x, p.y - 1));
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture, int algorithm)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    init_arr(m, n);

    for (int y = 0; y < m; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            int areaType = picture[y][x];
            if (areaType == 0)
                continue;

            int areaCount = 0;

            switch (algorithm)
            {
            case 0:
                get_area_size1(areaType, x, y, n, m, picture, areaCount);
                break;
            case 1:
                get_area_size2(areaType, Pos(x, y), n, m, picture, areaCount);
                break;
            case 2:
                get_area_size3(areaType, Pos(x, y), n, m, picture, areaCount);
                break;
            }

            if (areaCount > 0)
            {
                ++number_of_area;
                max_size_of_one_area = max(areaCount, max_size_of_one_area);
            }
        }
    }

    delete_arr(m);

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}



DFS::DFS()
{
    vector<vector<int>> picture = 
    {
        {{1, 1, 1, 0},{1, 1, 1, 0},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1}}
    };

    vector<int> answer = solution(6, 4, picture, 0);
    cout << endl;

    answer = solution(6, 4, picture, 1);
    cout << endl;

    answer = solution(6, 4, picture, 2);
    cout << endl;

    for (auto ans : answer)
        cout << ans << endl;
}
