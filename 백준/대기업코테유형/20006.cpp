#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int p, n, l, m; // 플레이어의 수, 플레이어의 닉네임, 플레이어의 레벨, 방 한개의 정원
vector<pair<int, string>> room[301];

bool cmp(pair<int, string> &a, pair<int, string> &b)
{
    return a.second < b.second;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> p >> m;

    string nickname;
    int level, roomCnt = 0;

    for (int i = 0; i < p; i++)
    {
        cin >> level >> nickname;

        for (int j = 0; j < 301; j++)
        {
            if (room[j].empty())
            {
                room[j].push_back({level, nickname});
                roomCnt++;
                break;
            }
            else if (room[j].size() == m)
            {
                continue;
            }
            else
            {
                int limitLevel = room[j].front().first;
                if (limitLevel + 10 >= level && limitLevel - 10 <= level)
                {
                    room[j].push_back({level, nickname});
                    break;
                }
            }
        }
    }

    for (int i = 0; i < roomCnt; i++)
    {
        sort(room[i].begin(), room[i].end(), cmp);

        if (room[i].size() == m)
        {
            cout << "Started!" << '\n';
        }
        else
        {
            cout << "Waiting!" << '\n';
        }

        for (int j = 0; j < room[i].size(); j++)
        {
            cout << room[i][j].first << " " << room[i][j].second << '\n';
        }
    }

    return 0;
}
