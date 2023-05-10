#include <iostream>

using namespace std;

int N = 4;
int W[4][4];
int result[4];
int COLOR = 3;

bool promising(int i)
{
    int j = 1;
    int Switch = true;
    while (j < i && Switch)
    {
        if (W[i][j] && result[i] == result[j])
            Switch = false;
        j++;
    }
}

void backtracking(int node)
{
    if (promising(node))
    {
        if (node == N)
        {
            // cout << result[1] ~ result[4] 결과값 출력
        }
        else
        {
            for (int color = 0; color < COLOR; color++)
            {
                result[node + 1] = color;
                backtracking(node + 1);
            }
        }
    }
}