#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<pair<int, int>> pig;
    int rank[51];

    for (int i = 0; i < 51; i++)
    {
        rank[i] = 1;
    }
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pig.push_back({x, y});
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pig[i].first < pig[j].first)
            {
                if (pig[i].second < pig[j].second)
                {
                    rank[i]++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << rank[i] << " ";
    }
    cout << '\n';

    return 0;
}
