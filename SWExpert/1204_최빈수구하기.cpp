/*
사실 처음 생각한건 계수정렬을 통해서 index에 점수를 대입하고 arr에서 가장 큰 값의
인덱스를 출력한다고 생각하고 풀었는데, 변수를 헷갈려서 maxCnt에다가 index 값을 넣고
계속 바꿔서 내가 뭔가 로직이 꼬였다고 생각하고 vector의 max_element를 통해서 풀었는데
상당히 바보같은 짓을 하였다. 변수의 들어가는 값과 로직을 똑바로 읽자.
아래 두 풀이는 모두 내가 쓴 풀이들이다.
*/

// 내가 쓴 풀이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("input (18).txt", "r", stdin);
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int tc_num;
        cin >> tc_num;

        vector<int> arr(101, 0);

        for (int i = 0; i < 1000; i++)
        {
            int a;
            cin >> a;
            arr[a]++;
        }

        int maxCount = max_element(arr.begin(), arr.end()) - arr.begin();

        int temp_cnt = max_element(arr.begin() + maxCount + 1, arr.end()) - arr.begin();

        if (arr[maxCount] <= arr[temp_cnt])
        {
            maxCount = temp_cnt;
        }

        cout << "#" << tc_num << " " << maxCount << '\n';
    }

    return 0;
}

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input (18).txt", "r", stdin);
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int num;
        cin >> num;

        int arr[101] = {
            0,
        };

        for (int i = 0; i < 1000; i++)
        {
            int a;
            cin >> a;

            arr[a]++;
        }

        int answer = 0;
        int maxCnt = arr[0];

        for (int i = 0; i <= 100; i++)
        {
            if (maxCnt <= arr[i])
            {
                answer = i;
                maxCnt = arr[i];
            }
        }

        cout << "#" << num << " " << answer << '\n';
    }

    return 0;
}
