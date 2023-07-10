#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool promising(int i);
void n_queen(int x);

vector<int> board;
int ans;
int n;

void n_queen(int x)
{
    if (promising(x))
    {
        if (x == n)
        {
            ans++;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            board[x + 1] = i;
            n_queen(x + 1);
        }
    }
}

bool promising(int i)
{
    bool endflag = true;
    int idx = 1;

    while (idx < i && endflag)
    {
        if (board[idx] == board[i] || abs(board[i] - board[idx]) == abs(i - idx))
        {
            endflag = false;
            break;
        }
        idx++;
    }
    return endflag;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ans = 0;
    cin >> n;

    board.resize(n + 1);

    n_queen(0);

    cout << ans << '\n';

    return 0;
}
