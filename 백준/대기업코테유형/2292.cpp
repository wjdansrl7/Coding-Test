#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // a(n) = a(n-1) + 6 * (n-1);
    int n;
    cin >> n;

    int dp[1000001] = {
        0,
    };

    dp[0] = 1;

    int k = 1;
    while (1)
    {
        dp[k] = dp[k - 1] + 6 * (k - 1);

        if (dp[k] >= n)
        {
            cout << k << '\n';
            return 0;
        }
        k++;
    }

    return 0;
}

// 다른 사람의 풀이
#include <iostream>
using namespace std;
int main()
{
    int number;
    cin >> number;
    int i = 0;
    for (int sum = 2; sum <= number; i++)
    {
        sum += 6 * i;
    }
    if (number == 1)
    {
        i = 1;
    }
    cout << i;
    return 0;
}
