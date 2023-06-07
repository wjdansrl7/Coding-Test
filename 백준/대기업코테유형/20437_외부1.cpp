// 1. 다른 사람의 풀이
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;

    while (T--)
    {
        string str;
        int k;

        cin >> str;
        cin >> k;

        // str의 알파벳 문자별로 등장 빈도수 저장
        vector<int> count(26);
        for (int i = 0; i < str.length(); i++)
            ++count[str[i] - 'a'];

        int answer3 = INT_MAX;
        int answer = -1;

        for (int i = 0; i < str.length(); i++)
        {
            if (count[str[i] - 'a'] < k)
            {
                continue;
            }

            int cnt = 0;
            for (int j = i; j < str.length(); j++)
            {
                if (str[i] == str[j])
                {
                    cnt++;
                }

                if (cnt == k)
                {
                    answer3 = min(answer3, j - i + 1);
                    answer4 = max(answer4, j - i + 1);
                    break;
                }
            }
        }

        if (answer == INT_MAX || answer == -1)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << answer3 << " " << answer4 << '\n';
        }
    }

    return 0;
}
