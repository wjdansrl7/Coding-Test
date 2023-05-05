#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char **argv)
{

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(2);
    q.push(1);

    while (!q.empty())
    {
        while (q.front() < 2)
        {
            cout << q.front() << " ";
            q.pop();
        }
        q.pop();
    }

    return 0;
}