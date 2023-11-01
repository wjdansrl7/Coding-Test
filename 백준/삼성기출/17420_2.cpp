#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A[100001];
int B[100001];

typedef struct TASK
{
    int A;
    int B;
} TASK;

vector<TASK> arr;

bool cmp(TASK a, TASK b)
{
    if (a.B == b.B)
    {
        return a.A < b.A;
    }
    else
    {
        return a.B < b.B;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++)
    {
        arr.push_back({A[i], B[i]});
    }

    long long answer = 0;

    sort(arr.begin(), arr.end(), cmp);

    int prev_max = arr[0].B;
    int cur_max = -1;

    for (int i = 0; i < N; i++)
    {
        if (prev_max > arr[i].A)
        {
            // 이전 구간의 최댓값 보다 기프티콘 사용날짜가 더 크다면 갱신
            if (prev_max < arr[i].B)
            {
                prev_max = arr[i].B;
            }

            // 29를 더하면 나머지가 1이상일 떄 몫을 1추가한 것과 같다.
            int cnt = ((prev_max - arr[i].A) + 29) / 30;
            arr[i].A += (cnt * 30);

            answer += cnt;
        }

        // 같은 구간의 최댓값 찾기
        cur_max = max(cur_max, arr[i].A);

        // 구간 변경시 같은 구간 값중 최댓값을 이전값으로 갱신
        if ((i + 1) < N && arr[i].B != arr[i + 1].B)
        {
            prev_max = cur_max;
        }
    }

    cout << answer;

    return 0;
}
