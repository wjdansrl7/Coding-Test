#include <iostream>
#include <queue>
using namespace std;

int n, w, l, ans, a[1000];
queue<int> q;

void input()
{
    cin >> n >> w >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void solution()
{
    int weightSum = 0;
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            if (q.size() == w)
            {
                weightSum -= q.front();
                q.pop();
            }
            if (a[i] + weightSum <= l)
                break;
            q.push(0);
            ans++;
        }
        q.push(a[i]);
        weightSum += a[i];
        ans++;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solution();
    cout << ans + w;

    return 0;
}
