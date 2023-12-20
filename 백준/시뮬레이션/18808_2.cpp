#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
int pan[41][41];
int sticker[11][11];

void rotation(int x, int y, int arr[11][11], int L);
void findSpace(int x, int y, int arr[11][11], int L);
void fillSpace(int st_x, int st_y, int x, int y, int arr[11][11]);
void input()
{
    memset(pan, 0, sizeof(pan) / sizeof(int));

    cin >> n >> m >> k;

    int a, b;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;

        memset(sticker, 0, sizeof(sticker) / sizeof(int));
        for (int j = 0; j < a; j++)
            for (int l = 0; l < b; l++)
                cin >> sticker[j][l];

        findSpace(a, b, sticker, 0);
    }
}

void findSpace(int x, int y, int arr[11][11], int L)
{
    for (int i = 0; i < n - x; i++)
    {
        for (int j = 0; j < m - y; j++)
        {
            // 시작점 (i, j)
            bool flag = true;
            for (int l = 0; l < x; l++)
            {
                for (int m = 0; m < y; m++)
                {
                    if (arr[l][m] == 1 && pan[i + l][j + m] == 1)
                    {
                        // 해당 위치에 이미 다른 스티커가 붙여져있는 것
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }

            if (flag)
            {
                // 공간을 채웠으므로
                fillSpace(i, j, x, y, arr);

                return;
            }
        }
    }

    // 모든 시작점을 시작했으나, 찾지 못하였다.
    rotation(x, y, arr, L);
}

void rotation(int x, int y, int arr[11][11], int L)
{
    if (L >= 3)
    {
        return;
    }

    int tmp[11][11] = {
        0,
    };
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            tmp[i][j] = arr[j][x - i - 1];
        }
    }

    findSpace(y, x, tmp, L + 1);

    // memset(arr, 0, sizeof(arr) / sizeof(int));

    // for (int i = 0; i < y; i++)
    // {
    //     for (int j = 0; j < x; j++)
    //     {
    //         arr[i][j] = tmp[i][j];
    //     }
    // }
}

void fillSpace(int st_x, int st_y, int x, int y, int arr[11][11])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (pan[st_x + i][st_y + j] == 0)
            {
                pan[st_x + i][st_y + j] = arr[i][j];
            }
        }
    }

    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << pan[i][j] << " ";
        }
        cout << '\n';
    }
}

void solution()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (pan[i][j] == 1)
            {
                res++;
            }
        }
    }
    cout << res << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << pan[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solution();

    return 0;
}
