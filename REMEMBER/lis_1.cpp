#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int dp[1001] = {
        0,
    };
    int arr[9] = {10, 20, 40, 25, 20, 50, 30, 70, 85};
    int n = 9;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == 0)
        {
            dp[i] = 1;
        }

        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }

    return 0;
}
