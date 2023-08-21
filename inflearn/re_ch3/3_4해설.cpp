#include <iostream>
using namespace std;

int sw, p[2][81], h[10][10], y[10][10], g[10][10], cnt = 0, pan[10][10];

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
    int xx = p[0][L];
    int yy = p[1][L];
    int gg = find(xx, yy);
    for (int i = 1; i <= 9; i++)
    {
        if (h[xx][i] == 0 && y[yy][i] == 0 && g[gg][i] == 0)
        {
            h[xx][i] = y[yy][i] = g[gg][i] = 1;
            pan[xx][yy] = i;
            DFS(L + 1);
            pan[xx][yy] = 0;
            h[xx][i] = y[yy][i] = g[gg][i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> pan[i][j];
            if (pan[i][j] == 0)
            {
                p[0][cnt] = i;
                p[1][cnt++] = ;
            }
            else
            {
                h[i][pan[i][j]] = 1;
                y[j][pan[i][j]] = 1;
                g[find(i, j)][pan[i][j]] = 1;
            }
        }
    }
    DFS(0);
    return 0;
}
