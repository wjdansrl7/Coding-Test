#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int visited[11][11];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int N, nCount;

void dfs(int start_x, int start_y)
{
    visited[start_x][start_y] = true;

    if (start_x >= N)
    {
        nCount++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = start_x + dx[i];
        int ny = start_y + dy[i];

        if (nx < 0 || nx > N || ny < 0 || ny > N)
        {
            continue;
        }

        if (/* condition */)
        {
            /* code */
        }
    }
}

int main(int argc, char const *argv[])
{

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        cin >> N;
        nCount = 0;

        // fill_n(visited, sizeof(visited), 0);

        for (int j = 1; j <= N; j++)
        {
            memset(visited, 0, sizeof(visited));
            dfs(1, j);
        }
    }

    return 0;
}
