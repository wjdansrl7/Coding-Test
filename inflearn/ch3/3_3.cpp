#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, pair<char, int>> &a, pair<int, pair<char, int>> &b)
{
    return a.first < b.first; // 오름차순 정렬
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);
    int n;
    cin >> n;

    unordered_map<char, int> ts;
    vector<int> res(n + 1, 0);
    vector<pair<int, pair<char, int>>> st;

    char team;
    int point;
    for (int i = 0; i < n; i++)
    {
        cin >> team >> point;
        st.push_back({point, {team, i + 1}});
    }

    sort(st.begin(), st.end(), cmp);

    int sum = 0;
    int j = 0;
    res[st[0].second.second] = 0;
    for (int i = 1; i < n; i++)
    {
        for (; j <= i; j++)
        {
            if (st[i].first > st[j].first) // 사로잡힘
            {
                ts[st[j].second.first] += st[j].first;
                sum += st[j].first;
                // j++;
            }
            else
            {
                res[st[i].second.second] = sum - ts[st[i].second.first];
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << '\n';
    }

    return 0;
}
