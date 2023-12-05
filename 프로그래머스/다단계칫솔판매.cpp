#include <bits/stdc++.h>
using namespace std;

int node[10001];
unordered_map<string, int> pool;
int account[10001] = {
    0,
};
void stairProfit(int parent, int amount);

void init(vector<string> enroll)
{
    for (int i = 1; i <= enroll.size() + 1; i++)
        node[i] = i;
    for (int i = 2; i <= enroll.size() + 1; i++)
        pool[enroll[i - 2]] = i;
}

// 그래프 만들기
void makeGraph(vector<string> enroll, vector<string> referral)
{
    for (int i = 0; i < referral.size(); i++)
    {
        // 바로 부모 노드까지만 연결이 되어있는 상태
        // 루트 노드 바로 다음 노드일 경우
        if (referral[i] == "-")
            node[pool[enroll[i]]] = 1;
        else
            node[pool[enroll[i]]] = pool[referral[i]];
    }
}

// 계좌 연결하기
void connectAccount(vector<string> seller, vector<int> amount)
{
    for (int i = 0; i < seller.size(); i++)
    {
        int profitAmount = 100 * amount[i];

        if (profitAmount * 0.1 >= 1)
        {
            account[pool[seller[i]]] += profitAmount - int(profitAmount * 0.1);

            int parent = node[pool[seller[i]]];
            stairProfit(parent, profitAmount * 0.1);
        }
        else
            account[pool[seller[i]]] += profitAmount;
    }
}

void stairProfit(int parent, int amount)
{
    if (node[parent] != parent)
    {

        if (amount * 0.1 >= 1)
        {
            account[parent] += amount - int(amount * 0.1);

            parent = node[parent];
            stairProfit(parent, amount * 0.1);
        }
        else
            account[parent] += amount;
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;

    init(enroll);
    makeGraph(enroll, referral);
    connectAccount(seller, amount);

    for (int i = 2; i <= enroll.size() + 1; i++)
        answer.push_back(account[i]);

    return answer;
}