#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    long long newScore;
    priority_queue<int> pq;

    cin >> n >> newScore >> p;

    pq.push(newScore);

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pq.push(x);
    }

    int res = 0;
    int same = 0;
    while (!pq.empty())
    {
        if (pq.top() > newScore)
        {
            res++;
            pq.pop();
        }
        else if (pq.top() == newScore)
        {
            res++;
            same++;
            pq.pop();
        }
        else
            break;
    }

    if (same > 0)
        same--;

    if (res > p)
        cout << -1;
    else
        cout << res - same;

    return 0;
}
