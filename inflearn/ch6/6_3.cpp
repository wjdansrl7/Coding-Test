#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int res[1001];

void exec(int x, int y)
{
    dp[x][y] = min(dp[x - 1][y], min(dp[x][y - 1], dp[x - 1][y - 1])) + 1;

    for (int i = 1; i <= dp[x][y]; i++)
    {
        res[i]++;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("in10.txt", "r", stdin);
    int n, m;
    string str;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> str;

        for (int j = 0; j < m; j++)
        {
            arr[i][j + 1] = str[j] - 48;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                exec(i, j);
            }
        }
    }

    int k = 1;
    while (res[k] != 0)
    {
        cout << k << " " << res[k++] << '\n';
    }

    return 0;
}
