#include <iostream>
#include <vector>
using namespace std;

// struct Edge
// {
//     int st;
//     int et;
//     int dist;

//     Edge(int a, int b, int c)
//     {
//         st = a;
//         et = b;
//         dist = c;
//     }
// };

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, st, et;
    cin >> n >> m;

    vector<pair<int, int>> v[n + 1];

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
        // v.push_back(Edge(a, b, c));
        // v.push_back(Edge(b, a, c));
    }

    cin >> st >> et;

    return 0;
}
