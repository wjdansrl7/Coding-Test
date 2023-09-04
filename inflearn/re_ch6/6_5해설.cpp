#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int unf[1001];
struct Edge
{
    int v1, v2;
    double dis;
    Edge(int a, int b, double c)
    {
        v1 = a;
        v2 = b;
        dis = c;
    }
    bool operator<(const Edge &b) const
    {
        return dis < b.dis;
    }
};

int Find(int v)
{
    if (v == unf[v])
        return v;
    else
        unf[v] = Find(unf[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
        unf[a] = b;
}

int main(int argc, char const *argv[])
{
    int n, m, i, j, v1, v2;
    double res = 0;
    scanf("%d %d", &n, &m);
    vector<Edge> Ed;
    vector<double> X, Y;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        X.push_back(a);
        Y.push_back(b);
        unf[i] = i;
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            double dis = sqrt((X[j] - X[i]) * (X[j] - X[i]) + (Y[j] - Y[i]) * (Y[j] - Y[i]));
            Ed.push_back(i, j, dis);
        }
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &v1, &v2);
        Union(v1 - 1, v2 - 1);
    }
    sort(Ed.begin(), Ed.end());

    for (int i = 0; i < Ed.size(); i++)
    {
        int fa = Find(Ed[i].v1);
        int fb = Find(Ed[i].v2);
        if (fa != fb)
        {
            res += Ed[i].dis;
            unf[fa] = fb;
        }
    }
    printf("%0.2f", res);

    return 0;
}
