#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    priority_queue<long long, vector<long long>, greater<>> minheap;

    cin >> n;

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 0)
        {
            if (minheap.empty())
                cout << 0 << '\n';
            else
            {
                cout << minheap.top() << '\n';
                minheap.pop();
            }
        }
        else
            minheap.push(x);
    }

    return 0;
}
