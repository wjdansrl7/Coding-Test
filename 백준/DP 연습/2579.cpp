// 2579번 계단 오르기 - 실패
// DP에 대한 실력 부족
// 규칙성을 찾아서 점화식을 세워야 한다.
// n = 1부터 차례대로 넣어가면서 규칙을 찾아본다.
// 참고한 자료: https://yabmoons.tistory.com/20

#include <iostream>

using namespace std;

int score[301];
int dp[301];

void solution(int score[301], int num)
{
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    dp[3] = max(score[1] + score[3], score[2] + score[3]);

    for (int i = 4; i <= num; i++)
    {
        dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
    }

    cout << dp[num] << "\n";
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;

    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        cin >> score[i];
    }

    solution(score, num);

    return 0;
}
