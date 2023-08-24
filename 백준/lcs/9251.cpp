#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, str2;
    cin >> str >> str2;

    for (int i = 1; i <= str.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[str.size()][str2.size()];

    return 0;
}
