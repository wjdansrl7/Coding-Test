#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int n;
        cin >> n;

        vector<int> player;
        unordered_map<int, int> team;
        unordered_map<int, int> score;

        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            team[x]++;
            player.push_back(x);
        }

        int s = 1;
        int cnt[201] = {
            0,
        };
        int cnt5[201];
        for (int i = 0; i < n; i++)
        {
            if (team[player[i]] == 6)
            {
                if (cnt[player[i]] < 4)
                {
                    cnt[player[i]]++;
                    score[player[i]] += s;
                }
                else if (cnt[player[i]] == 4)
                {
                    cnt5[player[i]] = s;
                    cnt[player[i]]++;
                }

                s++;
            }
        }

        int res, minScore = INT_MAX;
        for (int i = 1; i < 201; i++)
        {
            if (score[i] != 0)
            {
                if (minScore > score[i])
                {
                    res = i;
                    minScore = score[i];
                }
                else if (minScore == score[i])
                {
                    if (cnt5[res] > cnt5[i])
                    {
                        res = i;
                        minScore = score[i];
                    }
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
