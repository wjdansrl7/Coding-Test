#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2)
{
    if (v1[2] > v2[2])
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> costs = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};

    sort(costs.begin(), costs.end(), cmp);

    for (auto cost : costs)
    {
        cout << cost[0] << " " << cost[1] << " " << cost[2] << '\n';
    }

    return 0;
}
