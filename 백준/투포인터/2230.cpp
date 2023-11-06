#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
long long m;
vector<long long> v;

long long res = INT_MAX;
void selectedNum(int start, int end)
{
    while (start <= end && end < n)
    {
        if (v[end] - v[start] == m)
        {
            res = m;
            return;
        }
        else if (v[end] - v[start] > m)
        {
            res = min(res, v[end] - v[start]);
            start++;
        }
        else
        {
            end++;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    selectedNum(0, 0);

    cout << res;

    return 0;
}
