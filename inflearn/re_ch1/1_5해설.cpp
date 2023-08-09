#include <iostream>
#include <climits>
using namespace std;

struct Time
{
    int st, et, ev;
    Time(int a, int b, int c)
    {
        st = a;
        et = b;
        ev = c;
    }
    bool operator<(const Time &b) const
    {
        return et < b.et;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, r, a, b, c, answer = INT_MIN;
    cin >> n >> m >> r;
    vector<Time> gugan;
    vector<int> dy(m + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        gugan.push_back(Time(a, b, c));
    }
    sort(gugan.begin(), gugan.end());

    for (int i = 0; i < m; i++)
    {
        dy[i] = gugan[i].ev;
        for (int j = i - 1; j >= 0; j--)
        {
            if (gugan[j].et + r <= gugan[i].st && dy[j] + gugan[i].ev >= dy[i])
            {
                dy[i] = dy[j] + gugan[i].ev;
            }
        }
        answer = max(answer, dy[i]);
    }

    cout << answer;

    return 0;
}
