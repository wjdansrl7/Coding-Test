#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    // priority_queue<int> pq;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> q;

    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            q.push_back(num);
        }
    }
    sort(q.begin(), q.end(), greater<>());

    cout << q[n - 1] << '\n';

    return 0;
}
