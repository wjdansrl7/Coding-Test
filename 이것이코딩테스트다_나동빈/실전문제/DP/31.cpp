#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int d[401];
int arr[21][21];
int n, m;
int row;

int myMax(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            row = 0;
            return a;
        }
        else
        {
            row = 2;
            return c;
        }
    }
    else
    {
        if (b > c)
        {

            row = 1;
            return b;
        }
        else
        {
            row = 2;
            return c;
        }
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        d[i] += arr[i][1];
    }

    for (int i = 1; i <= n; i++)
    {
        int t = i;
        for (int j = 2; j <= m; j++)
        {
            if (t - 1 < 1)
            {
                if (arr[t][j] > arr[t + 1][j])
                {
                    row = 1;
                    d[i] += arr[t][j];
                }
                else
                {
                    row = 2;
                    d[i] += arr[t + 1][j];
                }
            }
            else if (t + 1 > n)
            {
                if (arr[t - 1][j] > arr[t][j])
                {
                    row = 0;
                    d[i] += arr[t - 1][j];
                }
                else
                {
                    row = 1;
                    d[i] += arr[t][j];
                }
            }
            else
            {
                d[i] += myMax(arr[t - 1][j], arr[t][j], arr[t + 1][j]);
            }

            if (row == 0)
            {
                t--;
            }
            else if (row == 2)
            {
                t++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int T;

    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        memset(d, 0, sizeof(d));
        memset(arr, -1, sizeof(arr));

        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
            }
        }

        solution();

        sort(d, d + n, greater<>());

        cout << d[0] << '\n';
    }

    return 0;
}
