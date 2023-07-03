/*
LIS: 앞에서부터 뒤로 숫자를 선태갛며 부분 수열을 구성해 나갈 때 증가하는 순서대로 숫자를 고르면서
고른 부분 수열의 길이가 최대 길이가 되도록 숫자를 선택하는 경우
보통 LIS를 구하는 문제의 답은 한 수열에서 주어지는 LIS의 길이가 답

dp[x]: x번째 수를 마지막 원소로 가지는 lis의 길이
*/

// O(n^2)

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

// https://jason9319.tistory.com/113

vt.push_back(-INF);
for (int i = 0; i < n; i++)
{
    scanf("%d", &x);
    if (vt.push_back() < x)
    {
        vt.push_back(x);
        ans++;
    }
    else
    {
        auto it = lower_bound(vt.begin(), vt.end(), x);
        *it = x;
    }
}
