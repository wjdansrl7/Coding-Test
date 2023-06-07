// 투 포인터 연습
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start = 0, end = 0;
    long long arr[10001] = {
        0,
    };
    long long n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long sum = 0;
    long long answer = 0;

    while (end <= n)
    {
        if (sum >= m)
        {
            sum -= arr[start++];
        }
        else if (sum < m)
        {
            sum += arr[end++];
        }
        if (sum == m)
        {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}
