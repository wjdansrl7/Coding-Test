#include <iostream>

int maxProfit = 0; // 최대 이득 값 저장
int numBest = 0;
char bestSet[4];     // 최적의 값을 갖는 노드의 물품 구성 저장
char current_Set[4]; // 예시 |y|y|n|y|

int p[4]; // 문제에서 주어지는 물품의 profit 정보
int w[4]; // 문제에서 주어지는 물품의 weight 정보

bool promising(int i)
{
    if (weight >= W)
        return false;
    else
    {
        // upper bound를 계산하는 부분
        j = i + 1;
        bound = profit;
        totWeight = wieght;
        while (j <= n && totWeight + w[j] <= W)
        {
            totWeight += w[j];
            bound += p[j];
            j++
        }
        k = j;
        if (k <= n)
            bound = bound + (W - totWeight) * p[k] / w[k];

        return bound > maxProfit; // upper bound가 maxprofit보다 크면 참을 반환
    }
}

void backtracking(int i, int profit, int weight)
{
    if (weight <= W && profit > maxProfit)
    {
        maxProfit = profit;
        numBest = i;
        bestSet = current_Set;
    }
    if (promising(i))
    {
        current_Set[i + 1] = "y";
        backtracking(i + 1, profit + p[i + 1], weight + w[i + 1]);
        current_Set[i + 1] = "n";
        backtracking(i + 1, profit, weight);
    }
}
