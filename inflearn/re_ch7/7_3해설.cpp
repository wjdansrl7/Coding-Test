#include <iostream>
#include <climits>
#include <vector>
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
        {
            sum += tmp[i];
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, m, lt = INT_MAX, rt = 0;
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
        {
            lt = mid + 1;
        }
    }
    cout << answer;

    return 0;
}
