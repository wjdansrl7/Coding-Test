#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, k;
int pan[13][13];
vector<pair<int, pair<int, int>>> v;
deque<int> info[200];

int dx[] = {0, 0, 0, -1, 1}; // 우, 좌, 상, 하
int dy[] = {0, 1, -1, 0, 0};

void Input()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> pan[i][j];

    int x, y, dir;
    for (int i = 1; i <= k; i++)
    {
        // 1번 체스말부터 차례대로 v에 입력
        cin >> x >> y >> dir;
        v.push_back({dir, {x, y}});

        // 해당 idx의 체스말 입력
        int idx = n * x + y;
        info[idx].push_back(i);
    }
}

void WhiteMove(int curr_x, int curr_y, int curr_dir, int nx, int ny, int dir, int idx)
{
    info[nx * n + ny].push_back(idx);
}

void RedMove()
{

}

void BlueMove()
{

}

void Move()
{
    for (int i = 0; i < v.size(); i++)
    {
        int curr_x = v[i].second.first;
        int curr_y = v[i].second.second;
        int curr_dir = v[i].first;

        // 해당 방향에 따른 이동
        int nx = curr_x + dx[curr_dir];
        int ny = curr_y + dy[curr_dir];

        if (pan[nx][ny] == 0) // 이동할 위치가 하얀색인 경우
        {
            WhiteMove(curr_x, curr_y, curr_dir, nx, ny, )
        }
        else if (pan[nx][ny] == 1) // 이동할 위치가 빨간색인 경우
        {
        }
        else // 이동할 위치가 파란색인 경우
        {
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
