#include <iostream>
#include <vector>

using namespace std;

vector<int> chess;
int N, sum;
void n_queen(int i);
bool promising(int i);

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        cin >> N;
        sum = 0;

        chess.resize(N + 1);

        n_queen(0);

        cout << "#" << tc + 1 << " " << sum << '\n';
    }

    return 0;
}

void n_queen(int i)
{
    if (promising(i))
    {
        if (i == N)
        {
            sum++;
        }
        else
        {
            for (int j = 1; j <= N; j++)
            {
                chess[i + 1] = j;
                n_queen(i + 1);
            }
        }
    }
}

bool promising(int i)
{
    int idx = 1;
    bool flag = true;

    while (idx < i && flag)
    {
        if (chess[idx] == chess[i] || abs(chess[i] - chess[idx]) == abs(i - idx))
        {
            flag = false;
        }
        idx++;
    }
    return flag;
}
