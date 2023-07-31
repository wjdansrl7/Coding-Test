#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[9], ch[9], team[3], res = INT_MAX;

void dfs(int L)
{
    if (L == 9)
    {
        vector<int> sum(3);
        for (int i = 0; i < 9; i++)
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
                team[i]++;
                ch[L] = i;
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
    cout << res;
    return 0;
}
