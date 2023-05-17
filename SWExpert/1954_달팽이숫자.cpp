#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for (int tc = 0; tc < T; tc++)
    {
        int N;
        cin >> N;

        int arr[11][11] = {
            0,
        };
        bool visited[11][11] = {
            false,
        };

        int a = 1;

        while (arr[a][a] == 0 && a <= N && !visited[a][a])
        {
            int start_x = a, start_y = a;
            visited[start_x][start_y] = true;
            arr[start_x][start_y] = arr[start_x][start_y - 1] + 1;

            int nx = start_x;
            int ny = start_y;

            for (int i = 0; i < 4; i++)
            {
                nx += dx[i];
                ny += dy[i];

                while (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny])
                {
                    arr[nx][ny] = arr[nx - dx[i]][ny - dy[i]] + 1;
                    visited[nx][ny] = true;
                    nx += dx[i];
                    ny += dy[i];
                }
                nx -= dx[i];
                ny -= dy[i];
            }
            a++;
        }

        cout << "#" << tc + 1 << '\n';
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}
