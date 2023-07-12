#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, r;
    cin >> n >> m >> r;

    vector<pair<int, pair<int, int>>> interval;

    int st, et, power;
    for (int i = 0; i < m; i++)
    {
        cin >> st >> et >> power;
        interval.push_back({power, {st, et}});
    }

    sort(interval.begin(), interval.end(), greater<>());

    vector<bool> visited(n + 1, 0);
    long long result = 0, res;
    for (int i = 0; i < interval.size(); i++)
    {
        // visited.clear();
        // memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n + 1; i++)
        {
            visited[i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << visited[i] << " ";
        }
        cout << '\n';

        res = 0;
        int curr_st = interval[i].second.first;
        int curr_et = interval[i].second.second;

        res += interval[i].first;

        for (int j = curr_st + 1; j < curr_et + r; j++)
        {
            visited[j] = true;
        }

        for (int j = 0; j < interval.size(); j++)
        {
            if (i == j)
            {
                continue;
            }

            int t_st = interval[j].second.first;
            int t_et = interval[j].second.second;
            int t_pw = interval[j].first;
            int flag = 1;

            for (int k = t_st + 1; k < t_et + r; k++)
            {
                if (!visited[k])
                {
                    continue;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
            {
                for (int k = t_st + 1; k < t_et + r; k++)
                {
                    visited[k] = true;
                }
                cout << t_pw << '\n';
                res += t_pw;
            }
        }
        if (result < res)
        {
            result = res;
        }
    }

    cout << result << '\n';

    return 0;
}
