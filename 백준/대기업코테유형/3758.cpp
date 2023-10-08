#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, t, m;
int i, j, s;
int solvedP[101][101] = {
    0,
};

struct Team
{
    int team_id;
    int last_submit;
    int score;
    int submit;
};

Team team[101];

bool cmp(const Team &t1, const Team &t2)
{
    if (t1.score == t2.score)
    {
        if (t1.submit == t2.submit)
        {
            return t1.last_submit < t2.last_submit;
        }
        else
        {
            return t1.submit < t2.submit;
        }
    }

    return t1.score > t2.score;
}

void solved(int idx, int a, int b, int s)
{
    team[a].last_submit = idx;
    team[a].submit++;

    if (solvedP[a][b] == 0)
    {
        solvedP[a][b] = s;
        team[a].score += s;
    }
    else
    {
        if (solvedP[a][b] < s)
        {
            team[a].score += s - solvedP[a][b];
            solvedP[a][b] = s;
        }
    }
}

void init()
{
    for (int i = 0; i < 101; i++)
    {
        team[i].team_id = i;
        team[i].last_submit = 0;
        team[i].score = 0;
        team[i].submit = 0;
    }

    memset(solvedP, 0, sizeof(solvedP));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        init();
        cin >> n >> k >> t >> m;

        for (int u = 0; u < m; u++)
        {
            cin >> i >> j >> s;
            solved(u, i, j, s);
        }

        sort(team, team + n + 1, cmp);

        for (int i = 0; i <= n; i++)
        {
            if (team[i].team_id == t)
            {
                cout << i + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}
