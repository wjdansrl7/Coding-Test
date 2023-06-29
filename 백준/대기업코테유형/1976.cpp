#include <iostream>
#include <vector>
using namespace std;

int p[201];
vector<int> v[201];
bool visited[201];

void getParent(int a, int b)
{
    visited[a] = true;

    if (p[a] > p[b])
    {
        p[a] = p[b];
    }
    else
    {
        p[b] = p[a];
    }
}

int check(int a)
{
    return p[a];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 201; i++)
    {
        p[i] = i;
    }

    int n, m, conn, travel;
    bool endflag = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> conn;

            if (conn == 1)
            {
                v[i].push_back(j);
                v[j].push_back(i);
                // getParent(i, j);
            }
        }
    }

    int k = 1;
    while (1)
    {
        int cnt = 0;

        for (int j = 0; j < v[k].size(); j++)
        {
            if (!visited[v[k][j]])
            {
                getParent(k, v[k][j]);
                k = v[k][j];
                break;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                cnt++;
            }
            else
                break;
        }
        if (cnt == n)
        {
            break;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         if (!visited[i])
    //         {
    //             getParent(i, v[i][j]);
    //         }
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << " ";
    }
    cout << '\n';

    cin >> travel;
    cin.ignore();

    int res = check(travel);

    for (int i = 1; i < m; i++)
    {
        cin >> travel;

        if (check(travel) != res)
            endflag = 1;
    }

    if (endflag)
    {
        cout << "NO" << '\n';
    }
    else
        cout << "YES" << '\n';

    return 0;
}
