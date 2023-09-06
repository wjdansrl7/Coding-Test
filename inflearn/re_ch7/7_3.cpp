#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<int> t(n, 0);

    for (int i = 0; i < n; i++)
        cin >> t[i];

    int lt = t[max_element(t.begin(), t.end()) - t.begin()];
    int rt = 0;
    int ans;
    for (auto x : t)
    {
        rt += x;
    }

    while (lt <= rt)
    {
        int mid = (lt + rt) / 2;
        int cnt = 1;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + t[i] <= mid)
            {
                sum += t[i];
            }
            else
            {
                cnt++;
                sum = t[i];
            }
        }

        if (cnt <= m)
        {
            ans = mid;
            rt = mid - 1;
        }
        else
        {
            lt = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
