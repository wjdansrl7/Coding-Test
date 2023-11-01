#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> v;
stack<pair<int, int>> stk;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long res = 0;
    cin >> n;

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (stk.empty())
        {
            stk.push({v[i], 0});
            continue;
        }

        int h = 0;
        while (!stk.empty() && stk.top().first < v[i])
        {
            h += stk.top().second + 1;
            res += stk.top().second;
            stk.pop();
        }

        stk.push({v[i], h});
    }

    while (!stk.empty())
    {
        res += stk.top().second;
        stk.pop();
    }

    cout << res;

    return 0;
}
