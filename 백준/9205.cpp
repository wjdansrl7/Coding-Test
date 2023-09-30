/**
 * @file 9205.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-28
 * BFS/DFS
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

int st_x, st_y, et_x, et_y, x, y, n;
vector<pair<int, pair<int, int>>> v;

bool visited[101];
stack<pair<int, pair<int, int>>> stk;

int distance(int a_x, int a_y, int b_x, int b_y)
{

    int dist = abs(a_x - b_x) + abs(a_y - b_y);

    return dist;
}

void DFS(int x, int y)
{
    stk.push({0, {x, y}});
    visited[0] = true;

    while (!stk.empty())
    {
        int xx = stk.top().second.first;
        int yy = stk.top().second.second;

        stk.pop();

        if (xx == et_x && yy == et_y)
        {
            cout << "happy\n";
            return;
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (!visited[v[i].first] && distance(xx, yy, v[i].second.first, v[i].second.second) <= 1000)
            {
                stk.push({v[i].first, {v[i].second.first, v[i].second.second}});
                visited[v[i].first] = true;
            }
        }
    }

    cout << "sad\n";
}

bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    if (a.second.first == b.second.first)
    {
        return a.second.second < b.second.second;
    }

    return a.second.first < b.second.first;
}

void init()
{
    v.clear();
    memset(visited, 0, sizeof(visited));
    while (!stk.empty())
    {
        stk.pop();
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        // 편의점 개수
        init();
        cin >> n;

        // 상근이 집
        cin >> st_x >> st_y;

        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            v.push_back({i, {x, y}});
        }

        cin >> et_x >> et_y;
        v.push_back({n + 1, {et_x, et_y}});

        sort(v.begin(), v.end(), cmp);

        DFS(st_x, st_y);
    }

    return 0;
}
