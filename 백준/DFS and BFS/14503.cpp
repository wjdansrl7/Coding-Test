#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int room[51][51];

// 북: 0, 동: 1, 남: 2, 서: 3
int dx[] = {-1, 0, 1, 0};
int r_dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int r_dy[] = {0, -1, 0, 1};

queue<pair<int, pair<int, int>>> q;
int cnt = 0;

void BFS(int x, int y, int d)
{
    q.push({d, {x, y}});
    bool endflag;

    while (!q.empty())
    {
        int xx = q.front().second.first;
        int yy = q.front().second.second;
        int dd = q.front().first;

        // 후진했을때 이미 지나간 길이라면 cnt++ X
        if (room[xx][yy] != 2)
        {
            cnt++;
            room[xx][yy] = 2;
        }
        q.pop();

        endflag = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            int nd;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && room[nx][ny] == 0)
            {
                // 90도 회전
                if (dd % 4 == 0)
                    nd = 3;
                else
                    nd = dd - 1;

                if (room[xx + dx[nd]][yy + dy[nd]] == 0)
                    q.push({nd, {xx + dx[nd], yy + dy[nd]}});
                else
                    q.push({nd, {xx, yy}});
                endflag = false;
                break;
            }
        }

        // 만약 4칸을 다돌렸는데, 청소되지 않은 빈칸이 없는 경우
        if (endflag)
        {
            int nx = xx + r_dx[dd];
            int ny = yy + r_dy[dd];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && room[nx][ny] != 1)
                q.push({dd, {nx, ny}});
            else
                return;
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int st_x, st_y, d;
    cin >> st_x >> st_y >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> room[i][j];

    BFS(st_x, st_y, d);

    cout << cnt << '\n';

    return 0;
}
