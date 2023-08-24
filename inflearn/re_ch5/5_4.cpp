#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[3001][3001];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in10.txt", "r", stdin);
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    string str, str2;
    cin >> str >> str2;

    str = '0' + str;
    str2 = '0' + str2;

    int len = str.size();
    int len2 = str2.size();

    for (int i = 1; i < len; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (str[i] == str2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << n1 * dp[len - 1][len2 - 1] + n2 * (max(len - 1, len2 - 1) - dp[len - 1][len2 - 1]);

    return 0;
}
