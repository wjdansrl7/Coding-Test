/*
맥주 한 박스: 20캔
50미터마다 한 병씩, 50미터 가기 직전에 맥주 한 병을 마셔야 함.
20캔을 넘어서는 안된다.
편의점, 상근이네 집, 펜타포트 락 페스티벌의 좌표

t: tc
편의점의 개수: n (0<= n <= 100)

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

void dfs(int v)
{
}

int main(int argc, char const *argv[])
{
    int tc;
    int n;
    int x, y;
    // vector<int> stk;
    int arr[102];

    cin >> tc;

    for (int t = 0; t < tc; t++)
    {
        memset(arr, 0, sizeof(arr));

        cin >> n;

        for (int i = 0; i < n + 2; i++)
        {
            cin >> x >> y;
            arr[i] = x + y;
        }

        sort(arr, arr + n + 2);
    }

    return 0;
}
