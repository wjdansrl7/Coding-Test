#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int n, k;
int pan[13][13];

// 0은 흰색, 1은 빨강, 2은 파랑
// 0은 그냥 그대로 하고, 빨강은 순서를 뒤바꾼다, 2은 반대방향으로 한칸이동한다.
// 문제는 횟수가 1000이상이거나 절대로 종료되지 않을 경우 -1을 출력
// 한칸에 말이 4개이상일 경우 게임이 종료된다. 우리는 횟수를 구한다.
struct horse
{
    int x;
    int y;
    int d;
    bool isBottom;

    horse(int a, int b, int c)
    {
        x = a;
        y = b;
        d = c;
    }
};

void move()
{
    for (int i = 0; i < k; i++)
    {
        
    }
    
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    horse h[10];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> pan[i][j];
        }
    }

    int a, b, c;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c;
        h[i].x = a;
        h[i].y = b;
        h[i].d = c;
        h[i].isBottom = true;
    }

    return 0;
}
