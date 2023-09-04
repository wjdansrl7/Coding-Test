#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    int n;
    cin >> n;
    priority_queue<int> a, b, c;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        c.push(x);
    }

    int res = -1;
    while (!a.empty() && !b.empty() && !c.empty())
    {
        int minRes = min(a.top(), min(b.top(), c.top()));

        while (!a.empty() && a.top() > minRes)
        {
            a.pop();
        }
        while (!b.empty() && b.top() > minRes)
        {
            b.pop();
        }
        while (!c.empty() && c.top() > minRes)
        {
            c.pop();
        }
        if (a.empty() || b.empty() || c.empty())
        {
            break;
        }

        if (a.top() == b.top() && b.top() == c.top())
        {
            res = a.top();
            break;
        }
    }

    cout << res;

    return 0;
}
