#include <iostream>
#include <cstring>

using namespace std;

int arr[101] = {
    0,
}; // 값을 저장하는 배열
int N;
int cnt;

void dfs(int start, int sumResult[20002])
{
    if (sumResult[start] == 1)
    {
        return;
    }

    sumResult[start]++;
    cnt++;

    for (int i = 0; i < N; i++)
    {
        dfs(start + arr[i], sumResult);
    }
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        cnt = 0;
        memset(arr, 0, sizeof(arr));

        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        // 해당 배열의 값이 1이라면 이미 한 번 거친 것이므로 더이상 조사하지 않는다. 중복에 대해서
        int sumResult[20002] = {
            0,
        };

        dfs(0, sumResult);

        cout << "#" << tc + 1 << " " << cnt << '\n';
    }

    return 0;
}
