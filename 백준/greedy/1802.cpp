// 1802번 종이접기
// 한 번 접을 때마다 두께는 2배, 길이는 절반
// 1은 시계방향: out, 0은 반시게 방향: in

// 한 번만 접는게 아니다.
#include <iostream>
#include <string>

using namespace std;

bool check(string s, int start, int end)
{
    if (start >= end - 1)
    {
        return true;
    }

    int j = end - 1;

    for (int i = 0; i < end / 2; i++)
    {
        if (s[i] == s[j])
        {
            return false;
        }
        else
        {
            j--;
            continue;
        }
    }

    return check(s, start, end / 2);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++)
    {
        string str;
        getline(cin, str);

        int endflag = 0;

        int strLength = str.length();

        // 길이가 짝수일 경우
        if (!(strLength & 1))
        {
            cout << "NO"
                 << "\n";
            continue;
        }

        if (check(str, 0, strLength))
            cout << "YES"
                 << "\n";
        else
        {
            cout << "NO"
                 << "\n";
        }
    }

    return 0;
}