#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[9], ch[9], sum[3], team[3];
int res = INT_MAX;
void dfs(int L)
{
    if (L == 9)
    {
        for (int i = 0; i < L; i++)
        {
            sum[ch[i]] += a[i];
        }
        int high = max(sum[0], max(sum[1], sum[2]));
        int low = min(sum[0], min(sum[1], sum[2]));
        res = min(res, high - low);
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (team[i] < 3)
            {
                ch[L] = i;
                team[i]++;
                dfs(L + 1);
                team[i]--;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
    }

    dfs(0);

    cout << res << '\n';

    return 0;
}
