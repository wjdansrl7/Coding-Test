/*
나는 배열을 차례대로 max값을 구해서 그 이전까지 값들의 차이를 sum에 저장하고, 다음 인덱스를 max 이후값으로 두고
idx가 vector의 마지막값까지 가도록 while문을 통해 반복하였는데,
다른 사람들의 풀이를 보니 N-1부터 0까지 거꾸로 가면서 max값보다 작으면 값을 sum하고,
현재 max보다 값이 크다면 max값을 변경하는 방식으로 사용하였다.
*/

// 나의 풀이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    vector<int> arr;
    freopen("input.txt", "r", stdin);

    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int n;
        cin >> n;

        arr.clear();

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr.push_back(a);
        }

        int maxIdx = 0;
        long long sum = 0;
        int i = 0;

        while (maxIdx != arr.size() - 1)
        {
            maxIdx = max_element(arr.begin() + i, arr.end()) - (arr.begin());

            if (maxIdx == 0)
                break;

            for (; i <= maxIdx; i++)
            {
                sum += (arr[maxIdx] - arr[i]);
            }
            i = maxIdx + 1;
        }

        cout << "#" << tc + 1 << " " << sum << '\n';
    }

    return 0;
}

// 다른 사람의 풀이
// 참고 : https://lily-lee.postype.com/post/2828835

#include <iostream>
using namespace std;
int num[10000002] = {
    0,
};

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        long long ans = 0;

        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> num[j];
        }

        int max_budget = num[N - 1];

        for (int j = N - 1; j >= 0; j--)
        {
            if (max_budget >= num[j])
            {
                ans = ans + (max_budget - num[j]);
            }
            else
                max_budget = num[j];
        }
        cout << "#" << i + 1 << " " << ans << '\n';
        for (int j = 0; j < N; j++)
        {
            num[j] = 0;
        }
    }

    return 0;
}