#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    set<double> curve;
    vector<int> result(51);

    long long h;
    for (int i = 1; i <= n; i++)
    {
        cin >> h;
        v.push_back({i, h});
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (v[i].second > v[j].second)
            {
                double a = (v[i].second - v[j].second) / (v[i].first - v[j].first);
                curve.insert(a);
            }
            else if (v[i].second == v[j].second)
            {
                curve.insert(0);
                break;
            }
            else
            {
                break;
            }
        }
        result[v[i].first] = curve.size();

        for (auto var : curve)
        {
            cout << var << " ";
        }
        cout << '\n';

        curve.clear();
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << result[i] << " ";
    // }

    return 0;
}
