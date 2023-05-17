#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int change;

// 최대 s
string maxS;

// maxS를 만들 수 있는 최소교환횟수
int minChangeCnt;

// 바뀐 change 값
int changeCnt;

// 정답값
string answer;

// 문자열 바꾸기
void swap(string &str, int x, int y)
{
    char tmp = str[x];
    str[x] = str[y];
    str[y] = tmp;
}

// 완전탐색(각 자리에서 다른 자리와 교환 or 교환X)
void go(int index, int cnt)
{

    // 모든 자리마다 탐색이 끝난 경우 : 종료
    if (index > s.length())
    {
        return;
    }

    // maxS를 찾아 낼 경우 : 교환 최소 횟수 갱신
    if (s == maxS)
    {
        if (minChangeCnt == -1 || cnt < minChangeCnt)
        {
            minChangeCnt = cnt;
        }
    }

    // 교환 횟수를 채운 경우 : 최대값 갱신 후 종료
    if (cnt == changeCnt)
    {
        if (answer == "" || stoi(s) > stoi(answer))
        {
            answer = s;
        }
        return;
    }

    // 각 자리마다 바꾸기
    for (int i = 0; i < s.length(); i++)
    {
        if (i == index)
        {
            go(index + 1, cnt);
        }
        else
        {
            swap(s, index, i);
            go(index + 1, cnt + 1);
            swap(s, i, index);
        }
    }
}

// 문자열에 같은 숫자가 있는지 없는지 판단
bool hasSame(string str)
{
    for (int i = 0; i < str.length() - 1; i++)
    {
        char check = str[i];
        for (int j = i + 1; j < str.length(); j++)
        {
            if (check == str[j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int test_case;
    int T;

    // freopen("input (17).txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; test_case++)
    {

        // 초기화
        answer = "";
        maxS = "";
        minChangeCnt = -1;
        changeCnt = 0;

        // 입력
        cin >> s >> change;

        // maxS : s로 만들 수 있는 최대값(s:12345 -> maxS:54321)
        maxS = s;
        sort(maxS.begin(), maxS.end(), greater<char>());

        // 교환 횟수 줄이기(최소 문자열 길이만큼만 바꿔도 최댓값을 만들 수 있으므로)
        changeCnt = change > s.length() ? s.length() : change;

        // 탐색
        go(0, 0);

        // 교환 횟수 안에 최댓값을 만들 수 있다면
        if (minChangeCnt != -1)
        {
            answer = maxS;

            // s에 같은 숫자가 있는 경우, 같은 숫자끼리 무한 반복 -> 최댓값 유지
            // s에 같은 숫자가 없는 경우, 뒤에 두 숫자를 바꿀지 말지 결정
            if (!hasSame(s))
            {
                //(교환횟수 - 최댓값을 만들 수 있는 최소교환횟수)가 홀수일 경우 뒤 두 숫자 교환
                if ((change - minChangeCnt) % 2 == 1)
                {
                    swap(answer, answer.length() - 2, answer.length() - 1);
                }
            }
        }

        // 출력
        cout << "#" << test_case << " " << answer << "\n";
    }

    // 종료
    return 0;
}