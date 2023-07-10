#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int tc = 0; tc < 3; tc++)
    {
        int n, money, cnt;
        priority_queue<int> pq;
        cin >> n;

        // 모든 동전을 큰 금액 순서대로 집어넣음
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> money >> cnt;
            sum += money * cnt;

            for (int j = 0; j < cnt; j++)
            {
                pq.push(money);
            }
        }

        bool flag = false;

        if (sum % 2 == 0)
        {
            int target = sum / 2;

            while (!pq.empty())
            {
                if (target == 0)
                {
                    // 성공
                    flag = true;
                    break;
                }

                if (target >= pq.top())
                {
                    target -= pq.top();
                }
                pq.pop();
            }
        }

        if (flag)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}
