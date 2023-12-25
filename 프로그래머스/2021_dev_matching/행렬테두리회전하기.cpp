#include <bits/stdc++.h>
using namespace std;

int pan[101][101];
int dx[] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[] = {1, 0, -1, 0};

void init(int rows, int columns)
{
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            pan[i][j] = (i - 1) * columns + j;
}

void dfs(int st_x, int st_y, int et_x, int et_y)
{
    bool visited[101][101];
    stack<pair<int, pair<int, int>>> stk;

    visited[st_x][st_y] = true;
    stk.push({pan[st_x][st_y], {st_x, st_y}});

    int dir = 0;
    while (!stk.empty())
    {
        int xx = stk.top().second.first;
        int yy = stk.top().second.second;
        int vv = stk.top().first;

        stk.pop();

        int nx = xx + dx[dir];
        int ny = yy + dy[dir];
        int nv = pan[nx][ny];

        while (nx < st_x || nx > et_x || ny < st_y || ny > et_y)
        {
            dir++;
            if (dir >= 4)
            {
                return;
            }
            nx = xx + dx[dir];
            ny = yy + dy[dir];
            nv = pan[nx][ny];
        }

        if (visited[nx][ny])
        {
            pan[nx][ny] = vv;
            return;
        }
        else
        {
            pan[nx][ny] = vv;
            visited[nx][ny] = true;
            stk.push({nv, {nx, ny}});
        }
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    init(rows, columns);

    for (int i = 0; i < queries.size(); i++)
    {
        int x1 = queries[i][0], y1 = queries[i][1], x2 = queries[i][2], y2 = queries[i][3];
        dfs(x1, y1, x2, y2);

        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= columns; j++)
                cout << pan[i][j] << " ";
            cout << '\n';
        }
    }

    return answer;
}