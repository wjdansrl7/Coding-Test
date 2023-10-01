#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

void shuffle()
{
    while (1)
    {
        if (q.size() == 1)
        {
            return;
        }
        else if (q.size() == 2)
        {
            q.pop();
            return;
        }
        else if (q.size() == 3)
        {
            q.pop();
            int front = q.front();
            q.pop();
            q.push(front);
            q.pop();
            return;
        }
        else
        {
            q.pop();
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    shuffle();

    cout << q.front();

    return 0;
}
