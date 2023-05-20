/*
내가 생각한 방식은 
// 가장 왼쪽 숫자부터 오른쪽에 있는 숫자들 중 가장 큰 값과 sort한다.
// 2번 제자리 sort 가능
// 만약 이미 값이 내림차순으로 정렬되어 있다면 짝수 횟수라면 값을 그대로 반환
// 홀수라면 가장 오른쪽에 있는 숫자를 서로 sort
// 그런데 만약 값들 중에 같은 숫자가 존재한다면 횟수와 관계없이 그대로 값을 출력 가능
이러한 방식으로 문제를 풀고 구현하려고 하였으나, 구현이 너무 복잡해서 완성하지 못하였다.

따라서 다른 사람의 풀이를 참고하였는데, 대부분 DFS를 활용해서 모든 경우의 수를 구하고 바꾼 횟수중에서
가장 최댓값을 구하도록 문제를 풀이하였다.
또한 문제에서 최대 자릿수는 여섯 자리이며, 숫자끼리의 change는 최대 10번이라고 하였을 때, 
*/

#include <iostream>
#include <algorithm>

using namespace std;



void swap(int a, int b, string str)
{
    string temp = "";
    temp += str[a];
    str[a] = str[b];
    str[b] = temp[0];
}

int main(int argc, char const *argv[])
{

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int number, nCount;

        cin >> number >> nCount;

        string str = str(number);
        string tmp = str;

        sort(tmp.begin(), tmp.end(), greater<>());
        if (str == tmp)
        {
            // 내림차순으로 정렬되어 있고, 교환횟수가 짝수라면
            if (nCount & 1 == 0)
            {
                cout << "#" << tc + 1 << " " << number << '\n';
                continue;
            }
            else
            {
                // 교환횟수는 홀수이지만, 같은 숫자가 존재한다면
                for (int i = 0; i < str.size(); i++)
                {
                    if (find(str.begin(), str.end(), str[i]) != str.end())
                    {
                        cout << "#" << tc + 1 << " " << number << '\n';
                        continue;
                    }
                }

                // 교환횟수가 홀수라면 한번만 교환해준다.
                string temp += str[str.size() - 1];
                str[str.size() - 1] = str[str.size() - 2];
                str[str.size() - 2] = temp[0];
                number = stoi(str);
                cout << "#" << tc + 1 << " " << number << '\n';
                continue;
            }
        }

        for (int i = 0; i < nCount; i++)
        {
            int maxN = i;
            int j;
            for (j = i; j < str.size(); j++)
            {
                if (str[i] <= str[j])
                {
                    maxN = j;
                }
            }
            swap(i, j, str);
        }
        number = stoi(str);
        cout << "#" << tc + 1 << " " << number << '\n';
    }

    return 0;
}
