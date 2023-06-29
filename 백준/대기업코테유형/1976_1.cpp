#include <iostream>
#include <vector>
using namespace std;

int p[201];
int find(int a)
{
    if (p[a] == a)
    {
        return a;
    }
    else
    {
        return find(p[a]);
    }
}

void union_parent(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a > b)
    {
        p[a] = b;
    }
    else if (a == b)
    {
        return;
    }
    else
    {
        p[b] = a;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int conn;
    cin >> n >> m;

    for (int i = 0; i <= 201; i++)
    {
        p[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> conn;
            if (conn == 1)
            {
                union_parent(i, j);
            }
        }
    }

    int endflag = 0;
    int x, res;

    cin >> x;
    cin.ignore();
    res = find(x);

    for (int i = 1; i < m; i++)
    {
        cin >> x;

        if (res != find(x))
        {
            endflag = 1;
        }
    }

    if (endflag)
    {
        cout << "NO" << '\n';
    }
    else
        cout << "YES" << '\n';

    return 0;
}
