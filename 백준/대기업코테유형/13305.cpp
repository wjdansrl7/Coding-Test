#include <iostream>
using namespace std;

long long dist[100001];
long long cost[100001];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
        cin >> dist[i];

    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    long long minCost = cost[1];

    long long res = 0;
    for (int i = 1; i < n; i++)
    {
        if (minCost > cost[i])
            minCost = cost[i];

        res += minCost * dist[i];
    }
    cout << res;

    return 0;
}
