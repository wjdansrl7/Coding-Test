#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

int l, r, c;
char arr[31][31][31];
bool visited[31][31][31] = {
    false,
};
queue<pair<int, pair<int, pair<int, int>>>> q;
int res;

void bfs(int x, int y, int z, int end_x, int end_y, int end_z)
{
    visited[z][x][y] = true;
    q.push({0, {z, {x, y}}});

    while (!q.empty())
    {
        int curr_dist = q.front().first;
        int curr_z = q.front().second.first;
        int curr_x = q.front().second.second.first;
        int curr_y = q.front().second.second.second;

        q.pop();

        if (curr_z == end_z && curr_x == end_x && curr_y == end_y)
        {
            if (res > curr_dist)
                res = curr_dist;

            continue;
        }

        for (int i = 0; i < 6; i++)
        {
            int nz = curr_z + dz[i];
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nz][nx][ny] || arr[nz][nx][ny] == '#')
            {
                continue;
            }
            else
            {
                visited[nz][nx][ny] = true;
                // q.push({nz, {nx, ny}});
                q.push({curr_dist + 1, {nz, {nx, ny}}});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        res = 987654321;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0)
        {
            break;
        }

        string str;
        int start_x, start_y, start_z;
        int end_x, end_y, end_z;

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                cin >> str;
                for (int k = 0; k < c; k++)
                {
                    if (str[k] == 'S')
                    {
                        // 시작지점 좌표 저장
                        start_z = i;
                        start_x = j;
                        start_y = k;
                    }

                    if (str[k] == 'E')
                    {
                        // 목표지점 좌표 저장
                        end_z = i;
                        end_x = j;
                        end_y = k;
                    }

                    arr[i][j][k] = str[k];
                }
            }
        }

        bfs(start_x, start_y, start_z, end_x, end_y, end_z);

        if (res != 987654321)
        {
            cout << "Escaped in " << res << " minute(s)." << '\n';
        }
        else
        {
            cout << "Trapped!" << '\n';
        }
    }

    return 0;
}
