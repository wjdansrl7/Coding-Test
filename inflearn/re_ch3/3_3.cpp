#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, pair<char, int>> &a, pair<int, pair<char, int>> &b)
{
    return a.second.second < b.second.second;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in1.txt", "r", stdin);
    int n;
    cin >> n;

    vector<pair<int, pair<char, int>>> st;

    char team;
    int score;
    for (int i = 0; i < n; i++)
    {
        cin >> team >> score;
        st.push_back({i + 1, {team, score}});
    }

    sort(st.begin(), st.end(), cmp);

    int teamScore[26] = {
        0,
    };
    vector<int> res(n + 1, 0);

    teamScore[int(st[0].second.first) - 97] += st[0].second.second;
    res[st[0].first] = 0;

    for (int i = 1; i < n; i++)
    {
        teamScore[int(st[i].second.first) - 97] += st[i].second.second;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (st[i].second.second == st[j].second.second)
            {
                if (st[i].second.first != st[j].second.first)
                {
                    res[st[i].first] -= st[j].second.second;
                }
            }
            if (st[i].second.second < st[j].second.second)
            {
                break;
            }

            // else if (st[i].second.second > st[j].second.second)
            // {
            //     for (int k = 0; k < 26; k++)
            //     {
            //         if (int(st[i].second.first) - 97 == k)
            //         {
            //             continue;
            //         }
            //         else
            //             res[st[i].first] += teamScore[k];
            //     }
            //     break;
            // }
        }
        for (int k = 0; k < 26; k++)
        {
            if (int(st[i].second.first) - 97 == k)
            {
                continue;
            }
            else
                res[st[i].first] += teamScore[k];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << '\n';
    }

    return 0;
}
