#include <bits/stdc++.h>
using namespace std;
int count(int limit, vector<int> tmp)
{
    int sum = 0, cnt = 1;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (sum + tmp[i] > limit)
        {
            cnt++;
            sum = tmp[i];
        }
        else
            sum += tmp[i];
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "rt", stdin);
    int n, m, lt = INT_MIN, rt = 0;
    cin >> n >> m;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        lt = max(lt, num[i]);
        rt += num[i];
    }
    int answer;
    while (lt <= rt)
    {
        int mid = (lt + rt) / 2;
        if (count(mid, num) <= m)
        {
            answer = mid;
            rt = mid - 1;
        }
        else
            lt = mid + 1;
    }
    cout << answer;
    return 0;
}