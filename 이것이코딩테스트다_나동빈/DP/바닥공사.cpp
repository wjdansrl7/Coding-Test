#include <iostream>

using namespace std;

int dp[1000];

void solution(int num)
{
    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i < num; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
    }

    cout << dp[num - 1] % 796796 << '\n';
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    solution(n);

    return 0;
}
