#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, p = 1000;
    cin >> n;

    vector<int> seats(n), dist(n);

    for (int i = 0; i < n; i++)
    {
        cin >> seats[i];

        if (seats[i] == 1)
        {
            p = 0;
        }
        else
        {
            p++;
            dist[i] = p;
        }
    }
    p = 1000;

    for (int i = n - 1; i >= 0; i--)
    {
        if (seats[i] == 1)
        {
            p = 0;
        }
        else
        {
            p++;
            dist[i] = min(dist[i], p);
        }
    }
    int res = *max_element(dist.begin(), dist.end());

    // for (int x : dist)
    // {
    //     res = max(res, x);
    // }
    cout << res;

    return 0;
}
