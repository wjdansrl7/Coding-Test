#include <iostream>

using namespace std;

int N = 4;
int W[4][4];
int result[4];
int COLOR = 3;


// 어느 두 노드가 서로 이어져있고, 이어져 있는 두 노드가 같은 색깔을 갖는다면
// 그것은 promising 하지 않은 상태
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
    return Switch;
}

// 모든 탐색이 끝났을 때 탐색을 종료하는 분기점
// promising하다면 해당 노드로 다음 탐색을 진행하는 부분
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