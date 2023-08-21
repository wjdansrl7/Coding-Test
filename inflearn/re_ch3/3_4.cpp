#include <iostream>
#include <vector>
using namespace std;

int h[10][10];
int g[10][10];
int y[10][10];
int pan[10][10];
vector<pair<int, int>> v;
int cnt;

int find(int x, int y)
{
    return x / 3 * 3 + y / 3;
}

void DFS(int L)
{
    if (L == cnt)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << pan[i][j] << " ";
            }
            cout << '\n';
        }

        exit(0);
    }
    else
    {
        int xx = v[L].first;
        int yy = v[L].second;
        int gg = find(xx, yy);

        for (int i = 1; i <= 9; i++)
        {
            if (h[xx][i] == 0 && y[yy][i] == 0 && g[gg][i] == 0)
            {
                pan[xx][yy] = i;
                h[xx][i] = 1;
                y[yy][i] = 1;
                g[gg][i] = 1;
                DFS(L + 1);
                pan[xx][yy] = 0;
                g[gg][i] = 0;
                y[yy][i] = 0;
                h[xx][i] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> pan[i][j];

            if (pan[i][j] == 0)
            {
                v.push_back({i, j});
            }
            else
            {
                h[i][pan[i][j]] = 1;
                y[j][pan[i][j]] = 1;
                g[find(i, j)][pan[i][j]] = 1;
            }
        }
    }
    cnt = v.size();

    DFS(0);

    return 0;
}
