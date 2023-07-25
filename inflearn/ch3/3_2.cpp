#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in3.txt", "r", stdin);

    int n;
    cin >> n;

    deque<int> q;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push_back(x);
    }

    sort(q.begin(), q.end(), greater<>());

    int sum = 0;
    int s1 = q[q.size() - 1], s2 = q[q.size() - 2];

    while (!q.empty())
    {

        int p1 = q[0], p2 = q[1];

        if (q.size() == 2)
        {
            sum += p1;
            break;
        }
        if (q.size() == 3)
        {
            sum += p1 + p2 + s1;
            break;
        }

        if (p1 + p2 + s1 * 2 < s2 * 2 + p1 + s1)
        {
            sum += p1 + p2 + s1 * 2;
            q.pop_front();
            q.pop_front();
        }
        else
        {
            sum += s2 * 2 + p1 + s1;
            q.pop_front();
            q.pop_front();
        }
    }

    cout << sum << '\n';

    return 0;
}