#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<int> score(301, 0);

bool Can(int mid)
{
    int cnt = 0;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += score[i];

        if (sum > mid)
        {
            sum = score[i];
            cnt++;
        }
    }
    cnt += 1;

    if (cnt <= m)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    cin >> n >> m;

    int lt = INT_MIN;
    int rt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
        lt = max(lt, score[i]);
        rt += score[i];
    }

    int ans = rt;
    while (lt <= rt)
    {
        int mid = (lt + rt) / 2;

        if (Can(mid))
        {
            rt = mid - 1;
            if (mid >= 100)
                ans = mid;
        }
        else
            lt = mid + 1;
    }

    cout << ans << '\n';

    return 0;
}
