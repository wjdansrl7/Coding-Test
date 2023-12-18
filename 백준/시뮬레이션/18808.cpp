#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int pan[41][41] = {
    0,
};
int cnt = 0;

void rotation(int x, int y, int arr[11][11], int L);
void startPoint(int x, int y, int arr[11][11]);
void input()
{
    cin >> n >> m >> k;

    int a, b;
    for (int i = 0; i < k; i++)
    {
        int sticker[11][11] = {
            0,
        };
        cin >> a >> b;

        for (int j = 0; j < a; j++)
        {
            for (int l = 0; l < b; l++)
            {
                cin >> sticker[j][l];
            }
        }
        startPoint(a, b, sticker);
    }
}

void startPoint(int x, int y, int arr[11][11])
{
    int i, j;
    for (i = 0; i <= n - x; i++)
    {
        for (j = 0; j <= m - y; j++)
        {
            bool flag = true;
            for (int m = 0; m < x; m++)
            {
                for (int l = 0; l < y; l++)
                {
                    if (arr[m][l] == 1 && pan[i + m][j + l] != 0)
                    {
                        flag = false;
                    }
                }
            }
            // cout << "flag = " << flag << '\n';
            // 해당 모양을 집어넣어도 됨
            if (flag)
            {
                for (int m = i; m < i + x; m++)
                {
                    for (int l = j; l < j + y; l++)
                    {
                        if (arr[m][l] == 1)
                        {
                            pan[m][l] = 1;
                        }
                    }
                }
                cnt = 0;

                cout << "===========\n";
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        cout << pan[i][j] << " ";
                    }
                    cout << '\n';
                }
                cout << "===========\n";

                return;
            }
            // 스티커를 90도 회전해야한다.
            else
            {
                rotation(x, y, arr, cnt);
            }
        }
    }
}

void rotation(int x, int y, int arr[11][11], int L)
{
    if (L == 3)
    {
        cnt = 0;
        return;
    }

    int tmp[11][11];
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            tmp[i][j] = arr[j][x - i - 1];
        }
    }
    cnt++;
    startPoint(y, x, tmp);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;

    input();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (pan[i][j] == 1)
            {
                ans++;
            }
        }
    }
    cout << ans << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << pan[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
