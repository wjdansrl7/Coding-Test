#include <iostream>
#include <vector>

using namespace std;

// 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화
int d[100];
int n;
vector<int> arr1;

int main(int argc, char const *argv[])
{
    // 정수 N을 입력받기
    cin >> n;
    // 모든 식량 정보 입력받기
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr1.push_back(x);
    }

    // 다이나믹 프로그래밍(Dynamic Programming) 진행(보텀업)
    d[0] = arr1[0];
    d[1] = max(arr1[0], arr1[1]);
    for (int i = 2; i < n; i++)
    {
        d[i] = max(d[i - 1], d[i - 2] + arr1[i]);
    }

    cout << d[n - 1] << '\n';

    return 0;
}
