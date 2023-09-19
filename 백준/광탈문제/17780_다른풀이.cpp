#include <iostream>
#include <vector>
using namespace std;

struct horse
{
    int x, y, d;
    bool is_bottom;
} h[10];

int n, k;
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
int turn[] = {0, 2, 1, 4, 3};
int color[13][13];
vector<int> info[13][13];

int move(int i)
{
    int tx = h[i].x + dx[h[i].d];
    int ty = h[i].y + dx[h[i].d];

    // 경계를 넘거나 파란 칸
    if (tx <= 0 || ty <= 0 || tx > n || ty > n || color[tx][ty] == 2)
    {
        // 방향 전환
        h[i].d = turn[h[i].d];

        tx = h[i].x + dx[h[i].d];
        ty = h[i].y + dy[h[i].d];

        if (tx <= 0 || ty <= 0 || tx > n || ty > n || color[tx][ty] == 2)
        {
            return 0;
        }
    }

    vector<int> &cur = info[h[i].x][h[i].y];
    vector<int> &next = info[tx][ty];

    // 3. 하얀 칸
    if (color[tx][ty] == 0)
    {
        if (!next.empty())
        {
            h[cur.front()].is_bottom = false;
            next.insert(next.end(), cur.begin(), cur.end());
        }
    }
    else if (color[tx][ty] == 1)
    {
        next.insert(next.end(), cur.rbegin(), cur.rend());
        h[next.back()].is_bottom = false;
        h[next.front()].is_bottom = true;
    }
    h[next.front()].x = h[next.back()].x = tx;
    h[next.front()].y = h[next.back()].y = ty;
    cur.clear();
    return next.size();
}

int simulation()
{
    int round, i, tx, ty, stack_cnt;

    // 라운드 반복
    for (round = 0; round < 1000; round++)
    {
        // 1. 자기 차례에 가장 아래에 있다면 이동
        for (i = 0; i < k; i++)
        {
            if (h[i].is_bottom)
            {
                stack_cnt = move(i);

                // 5. 말이 4이상 쌓이면 종료
                if (stack_cnt >= 4)
                {
                    return round;
                }
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> color[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        horse &ho = h[i];
        cin >> ho.x >> ho.y >> ho.d;
        ho.is_bottom = true;
        info[ho.x][ho.y].push_back(i);
    }
    cout << simulation();

    return 0;
}
