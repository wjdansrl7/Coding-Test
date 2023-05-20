#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input (20).txt", "r", stdin);
    int T = 0;
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++)
    {
        string s;
        cin >> s;         // decoding할 문자열
        string temp = ""; // bit 저장할 변수
        printf("#%d ", tc + 1);
        for (int i = 0; i <= s.length(); i++)
        {
            // 24 bit가 쌓였을 경우(총 4매의 문자를 확인)
            if (i > 0 && i % 4 == 0)
            {
                for (int j = 0; j < temp.size(); j += 8) // 8bit씩 잘라서 3문자로 바꿔준다.
                {
                    int idx = 7;
                    int tmp = 0;
                    for (int t = 0; t <= 7; t++)
                    {
                        if (temp[j + t] == '1')
                        {
                            tmp += 1 << idx;
                        }
                        idx--;
                    }
                    printf("%c", (char)tmp);
                }
                temp = ""; // 3문자 모두 교환했으니 다음 3문자를 위해 초기화
            }

            if (i == s.length())
            {
                continue;
            }

            // 24bit까지 쌓아야할 경우
            int val = 0;
            if (s[i] == '+')
            {
                val = 62;
            }
            else if (s[i] == '/')
            {
                val = 63;
            }
            else
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    val = s[i] + 4;
                }
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    val = s[i] - 65;
                }
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    val = s[i] - 97 + 26;
                }
            }

            for (int j = 5; j >= 0; j--)
            {
                if (val & (1 << j))
                {
                    temp += "1";
                }
                else
                {
                    temp += "0";
                }
            }
        }
        printf("\n");
    }

    return 0;
}
