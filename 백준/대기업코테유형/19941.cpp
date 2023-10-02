#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, k;
queue<pair<int, char>> q;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    string str;
    cin >> str;

    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (q.empty())
            q.push({i, str[i]});
        else
        {
            while (i - q.front().first > k)
                q.pop();

            if (q.front().second != str[i] && i - q.front().first <= k)
            {
                q.pop();
                cnt++;
            }
            else
                q.push({i, str[i]});
        }
    }

    cout << cnt;

    return 0;
}
