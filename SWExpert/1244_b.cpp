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
bool Visit[MAX][11];

void Initialize()
{
    Answer = 0;
    Inp.clear();
    memset(Visit, false, sizeof(Visit));
}

void Input()
{
    cin >> Inp;
    cin >> Change_Num;
}

int Invert(string S)
{
    int Sum = 0;
    for (int i = 0; i < S.length(); i++)
    {
        Sum = Sum + (S[i] - '0');
        if (i != S.length() - 1)
            Sum = Sum * 10;
    }
    return Sum;
}

void DFS(string S, int Depth)
{
    if (Depth == Change_Num)
    {
        int Inv_String = Invert(S);
        if (Inv_String > Answer)
            Answer = Inv_String;

        return;
    }

    for (int i = 0; i < S.length() - 1; i++)
    {
        for (int j = i + 1; j < S.length(); j++)
        {
            swap(S[i], S[j]);
            int Temp = Invert(S);
            if (Visit[Temp][Depth + 1] == false)
            {
                Visit[Temp][Depth + 1] = true;
                DFS(S, Depth + 1);
            }
            swap(S[i], S[j]);
        }
    }
}

void Solution()
{
    DFS(Inp, 0);
}

void Solve()
{
    int Tc;
    cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();

        cout << "#" << T << " " << Answer << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input (17).txt", "r", stdin);
    Solve();

    return 0;
}