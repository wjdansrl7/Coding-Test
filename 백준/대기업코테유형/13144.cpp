#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        minheap.push({x, i});
    }

    long long sum = 0;
    while (!minheap.empty())
    {
        int curr_data = minheap.top().first;
        int curr_idx = minheap.top().second;

        minheap.pop();

        if (minheap.empty())
        {
            sum += (n - curr_idx);
            break;
        }

        if (minheap.top().first == curr_data)
        {
            sum += (minheap.top().second - curr_idx);
        }
        else
        {
            sum += (n - curr_idx);
        }
    }

    cout << sum << '\n';

    return 0;
}
