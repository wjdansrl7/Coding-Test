#include <string>
#include <vector>

using namespace std;

/* abcdefghijklm || nopqrstuvwxyz
조이스틱을 왼쪽과 오른쪽으로 나누는 부분을 나누어서 생각해야한다.
ABABAAAAABAB 를 예시로 들면 원점부터 시작해서 A가 연속해서 나오기전까지를 i라고 하고
A가 연속으로 나온 이후에 다른 문자열이 나오는 곳을 ind라고 한다면,
원점에서 시작해서 왼쪽으로 커서가 이동해서 ind 부분까지 갔다가 돌아가는 경우와
오른쪽으로 가서 i까지 가고 다시 ind로 왼쪽으로 커서를 움직이는 경우 두 가지 경우의 수가
존재하는데, 두 가지 경우의 수 중에서 최솟값을 구하면 된다.
0 -> i = a
ind -> name.size() = b
n = name.size()
1) 0 -> i -> 0 -> ind : 2a + b
2) 0 -> ind -> 0 -> i : 2b + a

커서를 이동하는 횟수중에서 가장 최대값은 name.size() - 1
따라서 turn = n - 1라고 가정하면


min(2a+b, 2b+a) = a + b + min(a, b)

min(turn, i + n - ind + min(i, n - ind))로 계산하면 된다.

*/
int solution(string name)
{
    int answer = 0;
    int n = name.size();
    int turn = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (name[i] - 'A' <= 13)
        {
            answer += name[i] - 'A';
        }
        else
        {
            answer += 'Z' - name[i] + 1;
        }

        int ind = i + 1;

        while (name[ind] == 'A' && ind < n)
            ind++;

        turn = min(turn, i + n - ind + min(i, n - ind));
    }

    answer += turn;

    return answer;
}