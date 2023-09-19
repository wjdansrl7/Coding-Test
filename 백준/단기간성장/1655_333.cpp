#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<>> pq;
    queue<int> q;

    int x;
    for (int i = 0; i < 7; i++)
    {
        cin >> x;
        pq.push(x);

        int size = pq.size();

        if (size % 2 == 1)
        {
            for (int i = 0; i < size / 2; i++)
            {
                q.push(pq.top());
                pq.pop();
            }
            cout << pq.top() << '\n';

            while (!q.empty())
            {
                pq.push(q.front());
                q.pop();
            }
        }
        else
        {

            for (int i = 0; i < size / 2 - 1; i++)
            {
                q.push(pq.top());
                pq.pop();
            }
            cout << pq.top() << '\n';

            while (!q.empty())
            {
                pq.push(q.front());
                q.pop();
            }
        }
    }

    // while (!pq.empty())
    // {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    return 0;
}
