#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int n;
vector<int> board;
void n_queen(int i);
bool promising(int i);
unsigned long long sum = 0, Max = 0;
string a = "";

int main(int argc, char const *argv[])
{
    cin >> n;
    board.resize(n + 1);
    n_queen(0);
    cout << sum << endl
         << Max;

    return 0;
}

void n_queen(int i)
{
    if (promising(i) == 1)
    {
        if (i == n)
        {
            for (int i = 0; i < board.size(); i++)
            {
                a += to_string(board[i]);
            }

            long long int temp = stoll(a);
            if (Max < temp)
                Max = temp;
            a = "";
            sum++;
        }
        else
            for (int j = 1; j <= n; j++)
            {
                board[i + 1] = j;
                n_queen(i + 1);
            }
    }
}

bool promising(int i) // promising 할 때 가지치기 해야함
{
    int idx = 1;
    bool flag = true;
    while (idx < i && flag)
    {
        if (board[i] == board[idx] || abs(board[i] - board[idx]) == abs(i - idx))
        {
            flag = false;
        }
        idx++;
    }

    return false;
}
