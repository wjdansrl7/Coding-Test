#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    // vector<int> p;
    int p[4];
    priority_queue<pair<int, int>> pq;
    vector<int> priorities = {2, 1, 3, 2};

    pq.push({2, 1});
    pq.push({1, 2});
    pq.push({3, 4});
    pq.push({2, 6});

    for (int i = 0; i < 4; i++)
    {
        p[priorities[i]] = i;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << p[i] << " ";
    }

    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }

    return 0;
}
