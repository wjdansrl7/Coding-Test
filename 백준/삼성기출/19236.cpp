#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int arr[5][5];
int dir[5][5];
bool visited[17] = {
    false,
};

int res = INT_MIN;
// vector<vector<int>> dir(5, vector<int>(5, 0));
vector<pair<int, pair<int, int>>> v(17, {0, {0, 0}});
int sx, sy, sd;

void init()
{
    sx = 1;
    sy = 1;
    sd = dir[1][1];
    visited[arr[1][1]] = true;
    // res += arr[1][1];
}

void swap(int x, int y, int nx, int ny)
{
    // 해당 위치에 좌표 변경
    int tmp = arr[x][y];
    arr[x][y] = arr[nx][ny];
    arr[nx][ny] = tmp;

    // 해당 위치에 방향 변경
    int dTmp = dir[x][y];
    dir[x][y] = dir[nx][ny];
    dir[nx][ny] = dTmp;
}

void rotation()
{
    for (int i = 1; i < 17; i++)
    {
        // 아직 상어에게 잡아먹히지 않은 물고기
        if (!visited[i])
        {
            int x = v[i].second.first;
            int y = v[i].second.second;
            for (int j = 0; j < 8; j++)
            {
                int nx = x + dx[v[i].first % 8];
                int ny = y + dy[v[i].first % 8];

                // 물고기가 이동할 위치가 공간을 넘어가거나 상어와 위치가 같은 경우
                if (nx < 1 || nx > 4 || ny < 1 || ny > 4 || (sx == nx && sy == ny))
                {
                    v[i].first += 1;
                    continue;
                }
                // 이동할 수 있다면 swap
                else
                {
                    dir[x][y] = v[i].first;
                    swap(x, y, nx, ny);
                    break;
                }
            }
        }
    }
}

void DFS(int x, int y, int sum)
{
    rotation();

    for (int i = 1; i <= 3; i++)
    {
        int nx = x + dx[sd];
        int ny = x + dy[sd];

        if (nx < 1 || nx > 4 || ny < 1 || ny > 4)
        {
            res = max(res, sum);
            return;
        }
        else
        {
            if (!visited[arr[nx][ny]])
            {
                visited[arr[nx][ny]] = true;
                sx = nx;
                sy = ny;
                sd = dir[nx][ny];
                DFS(nx, ny, sum + arr[nx][ny]);
                visited[arr[nx][ny]] = false;
            }
        }
    }

    // int nx = x + dx[sd];
    // int ny = y + dy[sd];

    // while (1)
    // {

    //     if (nx < 1 || nx > 4 || ny < 1 || ny > 4)
    //     {
    //         res = max(res, sum);
    //         // cout << res << '\n';
    //         return;
    //     }
    //     else
    //     {
    //         if (!visited[arr[nx][ny]])
    //         {
    //             sum += arr[nx][ny];
    //             sx = nx;
    //             sy = ny;
    //             sd = dir[nx][ny];
    //             cout << sum << '\n';
    //             visited[arr[nx][ny]] = true;

    //             DFS(sx, sy, sum);
    //             visited[arr[nx][ny]] = false;
    //             sum -= arr[nx][ny];
    //         }
    //     }
    //     nx += dx[sd];
    //     ny += dy[sd];
    // }

    // int nx = x + dx[sd];
    // int ny = y + dy[sd];

    // while (nx <= 4 && ny <= 4 && nx >= 1 && ny >= 1)
    // {
    //     if (!visited[arr[nx][ny]])
    //     {
    //         sum += arr[nx][ny];
    //         sx = nx;
    //         sy = ny;
    //         sd = dir[nx][ny];

    //         visited[arr[nx][ny]] = true;
    //         DFS(nx, ny, sum);
    //         sum -= arr[nx][ny];
    //         visited[arr[nx][ny]] = false;
    // sum += arr[nx][ny];
    // sx = nx;
    // sy = ny;
    // sd = dir[nx][ny];
    // visited[arr[nx][ny]] = true;
    // DFS(nx, ny, sum);
    // sum -= arr[nx][ny];
    // sd = dir[nx - dx[sd]][ny - dy[sd]];
    // sx -= dx[sd];
    // sy -= dy[sd];
    // visited[arr[nx][ny]] = false;
    // }
    //     nx += dx[sd];
    //     ny += dy[sd];
    // }

    // res = max(res, sum);
    // cout << res << '\n';
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> x >> y;
            arr[i][j] = x;     // 물고기의 번호 저장
            dir[i][j] = y - 1; // 물고기의 방향 저장
            v[x].first = y - 1;
            v[x].second.first = i;
            v[x].second.second = j;
        }
    }

    init();

    DFS(1, 1, arr[1][1]);

    cout << res;

    return 0;
}
