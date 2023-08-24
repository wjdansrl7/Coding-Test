#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> n(10, 0);
vector<int> team(10, 0);
int tA, tB, tC;
int res = INT_MAX;

void DFS(int L)
{
    if (L == 9)
    {
        int teamA = 0, teamB = 0, teamC = 0;
        for (int i = 0; i < L; i++)
        {
            if (team[i] == 1)
            {
                teamA += n[i];
            }
            else if (team[i] == 2)
            {
                teamB += n[i];
            }
            if (team[i] == 3)
            {
                teamC += n[i];
            }
        }
        // cout << teamA << " " << teamB << " " << teamC << '\n';

        res = min(res, abs(max(teamA, max(teamB, teamC)) - min(teamA, min(teamB, teamC))));
    }
    else
    {
        if (tA < 3)
        {
            team[L] = 1;
            tA++;
            DFS(L + 1);
            tA--;
            team[L] = 0;
        }
        if (tB < 3)
        {
            team[L] = 2;
            tB++;
            DFS(L + 1);
            tB--;
            team[L] = 0;
        }
        if (tC < 3)
        {
            team[L] = 3;
            tC++;
            DFS(L + 1);
            tC--;
            team[L] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in1.txt", "r", stdin);

    for (int i = 0; i < 9; i++)
    {
        cin >> n[i];
    }

    DFS(0);

    cout << res;

    return 0;
}
