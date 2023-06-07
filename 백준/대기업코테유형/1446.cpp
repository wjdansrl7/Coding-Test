#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct cmp
{
    bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
    {

        double aWeight = ((a.second.second - a.second.first) / a.first);
        double bWeight = ((b.second.second - b.second.first) / b.first);

        if (aWeight == bWeight)
        {
            if (a.second.first == b.second.first)
            {
                return a.second.second < b.second.second;
            }

            return a.second.first > b.second.first;
        }
        else
        {
            return aWeight >= bWeight;
        }
    }
};

int main(int argc, char const *argv[])
{
    int n, d;
    cin >> n >> d;

    // queue<pair<int, pair<int, int>>> q;
    int arr[10001];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;

    for (int i = 0; i <= 10000; i++)
    {
        arr[i] = 1;
    }

    int x, y, z;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;

        if (x >= d || y > d)
        {
            continue;
        }

        if (z == 0)
        {
            for (int j = x; j < y; j++)
            {
                arr[j] = 0;
            }
            continue;
        }

        pq.push({z, {x, y}});
    }

    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second.first << " " << pq.top().second.second << '\n';
        pq.pop();
    }

    return 0;
}
