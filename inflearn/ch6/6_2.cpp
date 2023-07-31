#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    int n;
    cin >> n;

    priority_queue<long long> a, b, c;

    long long x;
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

    long long res = -1;
    while ((!a.empty()) && (!b.empty()) && (!c.empty()))
    {
        long long minNum = min(a.top(), min(b.top(), c.top()));

        while (!a.empty() && a.top() > minNum)
        {
            a.pop();
        }
        while (!b.empty() && b.top() > minNum)
        {
            b.pop();
        }
        while (!c.empty() && c.top() > minNum)
        {
            c.pop();
        }

        if (a.top() == b.top() && b.top() == c.top())
        {
            res = a.top();
            break;
        }
    }

    cout << res << '\n';

    return 0;
}
