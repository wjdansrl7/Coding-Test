#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({1, 2});
    pq.push({2, 2});
    pq.push({2, 3});
    pq.push({3, 4});

    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << '\n';
        pq.pop();
    }

    return 0;
}
