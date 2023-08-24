#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

    int i = len - 1;
    int j = len2 - 1;
    stack<int> stk;

    cout << dp[i][j] << '\n';

    while (dp[i][j] != 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1])
        {
            j--;
        }
        else if (dp[i][j] - 1 == dp[i - 1][j - 1])
        {
            stk.push(i);
            i--;
            j--;
        }
    }

    while (!stk.empty())
    {
        cout << str[stk.top()];
        stk.pop();
    }

    return 0;
}
