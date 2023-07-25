#include <iostream>
#include <vector>
using namespace std;

int arr[10][10];
int c[10][10];
int r[10][10];
int g[10][10];
int p[2][81];
int cnt = 0;

int find(int x, int y)
{
    return x / 3 * 3 + y / 3;
}

void dfs(int L)
{
    if (L == cnt)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0); // 프로그램 자체가 종료
    }

    int x = p[0][L];
    int y = p[1][L];
    int idx = find(x, y);
    for (int i = 1; i <= 9; i++)
    {
        if (c[y][i] == 0 && r[x][i] == 0 && g[idx][i] == 0)
        {
            arr[x][y] = i;
            c[y][i] = r[x][i] = g[idx][i] = 1;
            dfs(L + 1);
            c[y][i] = r[x][i] = g[idx][i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("in5.txt", "r", stdin);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 0)
            {
                p[0][cnt] = i;
                p[1][cnt++] = j;
            }
            else
            {
                r[i][arr[i][j]] = 1;
                c[j][arr[i][j]] = 1;

                int gIdx = find(i, j);
                g[gIdx][arr[i][j]] = 1;
            }
        }
    }
    dfs(0);

    return 0;
}
