#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> v;
bool visited[16];
char res[16];
vector<char> m = {'a', 'e', 'i', 'o', 'u'};

void dfs(int L, int jCnt, int mCnt)
{
    int cnt = jCnt + mCnt;

    if (cnt == l)
    {
        if (jCnt >= 2 && mCnt >= 1)
        {
            for (int i = 0; i < l; i++)
            {
                cout << res[i];
            }
            cout << '\n';
        }
        return;
    }
    else
    {
        for (int i = L; i < v.size(); i++)
        {
            if (visited[i])
                continue;

            bool flag = false;
            for (auto s : m)
            {
                if (s == v[i])
                {
                    flag = true;
                    break;
                }
            }

            visited[i] = true;
            res[cnt] = v[i];
            if (flag)
                dfs(i + 1, jCnt, mCnt + 1);
            else
                dfs(i + 1, jCnt + 1, mCnt);
            visited[i] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> c;

    char x;
    for (int i = 0; i < c; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    dfs(0, 0, 0);

    return 0;
}
