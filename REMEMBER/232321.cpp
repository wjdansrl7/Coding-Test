#include <iostream>

using namespace std;

int N; // 체스판 사이즈
int col[15];
int result = 0;

bool promising(int i)
{
    for (int j = 0; j < i; j++)
    {
        if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
        {
            return false;
        }
    }
    return true;
}

void N_queen(int i)
{
    if (i == N)
    {
        result += 1;
    }
    else
    {
        for (int j = 0; j < N; j++)
        {
            col[i] = j;
            if (promising(i))
                N_queen(i + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> N;
    N_queen(0);
    cout << result << endl;
    return 0;
}
