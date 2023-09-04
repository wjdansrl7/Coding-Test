#include <iostream>
#include <queue>
using namespace std;

int ch[10001];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in5.txt", "r", stdin);
    int s, e, k, p;
    cin >> s >> e >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> p;
        ch[p] = 1;
    }

    queue<int> q;

    q.push(s);
    ch[s] = 1;

    int L = 0;
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            int x = q.front();
            q.pop();
            for (int nx : {x + 1, x - 1, x + 5})
            {
                if (nx == e)
                {
                    cout << L + 1;
                    exit(0);
                }
                else if (nx > 0 && nx < 10000 && ch[nx] == 0)
                {
                    ch[nx] = 1;
                    q.push(nx);
                }
            }
        }
        L++;
    }

    return 0;
}
