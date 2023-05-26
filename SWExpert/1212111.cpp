#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input12.txt", "r", stdin);
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int N;
        cin >> N;
        queue<pair<int, int>> q;
        int answer = 0;

        for (int i = 0; i < N; i++)
        {
            int x, power;
            cin >> x >> power;

            q.push({x, power});
        }

        // while (!q.empty())
        // {
        //     int curr_x = q.front().first + q.front().second;
        //     q.pop();
        //     answer++;

        //     for (int i = 0; i < q.size(); i++)
        //     {
        //         if (curr_x >= q.front().first)
        //         {
        //             q.pop();
        //         }
        //     }
        // }

        do
        {
            int curr_x = q.front().first + q.front().second;
            q.pop();
            answer++;

            while (!q.empty() && curr_x >= q.front().first)
            {
                q.pop();
            }

        } while (!q.empty());

        cout << "#" << tc + 1 << " " << answer << '\n';
    }

    return 0;
}
