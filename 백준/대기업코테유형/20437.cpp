/*
내가 작성한 풀이인데, 기본적으로 배열안에 알파벳이 들어간 인덱스를 저장하고, 거기서 K개
에 맞는 개수를 찾아내는 방식으로 사용하였다.
투 포인터 방식과 유사하나 나의 코드는 조금 복잡하게 짠 것 같아 다른 사람의 풀이도 공부했다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string w;
    int k;

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        vector<int> alpha[26];
        cin >> w;
        cin >> k;

        int minResult = 987654321;
        int maxResult = 0;
        for (int i = 0; i < w.size(); i++)
        {
            alpha[int(w[i] - 'a')].push_back(i);
        }

        for (int i = 0; i < 26; i++)
        {
            if (alpha[i].size() >= k)
            {
                for (int j = 0; j <= alpha[i].size() - k; j++)
                {
                    if (minResult > alpha[i][j + k - 1] - alpha[i][j] + 1)
                    {
                        minResult = alpha[i][j + k - 1] - alpha[i][j] + 1;
                    }
                }

                if (minResult == k)
                {
                    break;
                }
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (alpha[i].size() >= k)
            {
                for (int j = 0; j <= alpha[i].size() - k; j++)
                {
                    if (maxResult < alpha[i][j + k - 1] - alpha[i][j] + 1)
                    {
                        maxResult = alpha[i][j + k - 1] - alpha[i][j] + 1;
                    }
                }

                if (maxResult == w.size())
                {
                    break;
                }
            }
        }

        if (minResult == 987654321)
        {
            minResult = -1;
        }

        if (maxResult == 0)
        {
            maxResult = -1;
        }

        if (minResult == maxResult && minResult == -1)
        {
            cout << minResult << '\n';
        }
        else
        {
            cout << minResult << " " << maxResult << '\n';
        }
    }

    return 0;
}
