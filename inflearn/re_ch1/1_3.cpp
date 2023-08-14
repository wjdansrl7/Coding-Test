#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in2.txt", "r", stdin);

    int n;
    cin >> n;

    stack<pair<int, int>> stk;
    vector<pair<int, int>> v;

    int height;
    for (int i = 0; i < n; i++)
    {
        cin >> height;
        v.push_back({height, i + 1});
    }

    vector<int> res;

    stk.push({v[0].first, v[0].second});
    res.push_back(0);

    for (int i = 1; i < n; i++)
    {
        if (stk.top().first > v[i].first)
        {
            res.push_back(stk.top().second);
            stk.push({v[i].first, v[i].second});
        }
        else
        {
            while (!stk.empty() && stk.top().first <= v[i].first)
                stk.pop();

            if (stk.empty())
                res.push_back(0);
            else
                res.push_back(stk.top().second);

            stk.push({v[i].first, v[i].second});
        }
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";

    return 0;
}
