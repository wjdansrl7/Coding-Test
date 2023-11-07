#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<pair<int, int>> stk;
    vector<int> res(n, -1);

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        while (!stk.empty() && stk.top().second < x)
        {
            res[stk.top().first] = x;
            stk.pop();
        }

        stk.push({i, x});
    }

    for (auto v : res)
        cout << v << " ";

    return 0;
}
