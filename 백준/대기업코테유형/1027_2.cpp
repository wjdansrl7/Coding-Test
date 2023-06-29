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

    int l = 0;
    for (int i = 0; i < n; i++)
    {
        for (; l < n; l++)
        {
            if (i == l)
            {
                continue;
            }

            if (v[i].second > v[l].second)
            {
                double a = (v[i].second - v[l].second) / (v[i].first - v[l].first);
                curve.insert(a);
            }
            else if (v[i].second == v[l].second)
            {
                curve.insert(0);
                break;
            }
            else
            {
                break;
            }
        }
        l = v[i].first;
        i = v[l].second;
        result[v[i].first] = curve.size();

        for (auto var : curve)
        {
            cout << var << " ";
        }
        cout << '\n';

        curve.clear();
    }

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
