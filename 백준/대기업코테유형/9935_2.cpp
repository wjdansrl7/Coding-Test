#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    clock_t start, end;
    double result;

    start = clock();

    string a, b;
    string t = "";
    cin >> a >> b;
    int a_len = a.length();
    int b_len = b.length();
    for (int i = 0; i < a_len; i++)
    {
        t += a[i];
        if (t.length() >= b_len)
        {
            bool flag = true;
            for (int j = 0; j < b_len; j++)
            {
                if (t[t.length() - b_len + j] != b[j])
                {
                    flag = false;
                    break;
                } // t뒤에서 폭발 문자열 길이만큼 비교
            }

            if (flag)
            {
                t.erase(t.end() - b_len, t.end());
            }
        }
    }
    if (t.empty())
    {
        cout << "FRULA" << '\n';
    }
    else
    {
        cout << t << '\n';
    }

    end = clock();
    result = (double)(end - start);

    cout << "수행 시간" << result << "millisecond" << '\n';

    return 0;
}
