#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        string str;
        int k;

        cin >> str;
        cin >> k;

        vector<int> alpha_pos[26];
        int answer3 = INT_MAX;
        int answer4 = -1;

        // 문자(인덱스)별로 그 문자가 등장하는 위치 인덱스들을 저장
        for (int i = 0; i < str.length(); i++)
        {
            alpha_pos[str[i] - 'a'].push_back(i);
        }

        for (int i = 0; i < 26; i++)
        {
            if (alpha_pos[i].size() >= k)
            {
                int l = 0;
                int r = k - 1;

                int temp3 = alpha_pos[i][r] - alpha_pos[i][l] + 1;
                int temp4 = alpha_pos[i][r] - alpha_pos[i][l] + 1;
                while (r < alpha_pos[i].size() - 1)
                {
                    r++;
                    l++;
                    temp3 = min(alpha_pos[i][r] - alpha_pos[i][l] + 1, temp3);
                    temp4 = max(alpha_pos[i][r] - alpha_pos[i][l] + 1, temp4);
                }

                answer3 = min(temp3, answer3);
                answer4 = max(temp4, answer4);
            }
        }

        if (answer == INT_MAX)
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
