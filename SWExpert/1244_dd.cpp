#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>

#define endl "\n"
#define MAX 1000000
using namespace std;

string Inp;
int Change_Num;
int Answer;
bool visited[MAX][11];

void Initialize()
{
    Answer = 0;
    Inp.clear();
    memset(visited, false, sizeof(visited));
}

void Input()
{
    cin >> Inp;
    cin >> Change_Num;
}

int Invert(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += (s[i] - '0');
        if (i != s.length() - 1)
        {
            sum *= 10;
        }
    }
    return sum;
}

void dfs(string s, int depth)
{
    if (depth == Change_Num)
    {
        int Inv_String = Invert(s);
        if (Inv_String > Answer)
        {
            Answer = Inv_String;
        }
        return;
    }

    for (int i = 0; i < s.length() - 1; i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            swap(s[i], s[j]);
            int temp = Invert(s);
            if (!visited[temp][depth + 1])
            {
                visited[temp][depth + 1] = true;
                dfs(s, depth + 1);
            }
            swap(s[i], s[j]);
        }
    }
}

void solution()
{
    dfs(Inp, 0);
}

void solve()
{
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        Initialize();
        Input();
        solution();

        cout << "#" << tc + 1 << " " << Answer << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input (17).txt", "r", stdin);
    solve();
    return 0;
}
