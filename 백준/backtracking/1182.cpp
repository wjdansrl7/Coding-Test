#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
vector<int> v;
int res = 0;

void partialSum(int len, int sum)
{
    if (sum == s && len != 0)
    {
        res++;
    }

    if (len == n)
    {
        return;
    }

    for (int i = len; i < n; i++)
    {
        partialSum(i + 1, sum + v[i]);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    partialSum(0, 0);

    cout << res;

    return 0;
}