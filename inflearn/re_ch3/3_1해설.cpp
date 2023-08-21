#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    char t;
    cin >> n >> t;
    t = toupper(t);
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        // transform()을 이용해서 대문자로 변환
        transform(a.begin(), a.end(), a.begin(), ::toupper);

        if (a.find(t) != string::npos)
        {
            // 중복 문자 제거
            string res = "";
            for (int i = 0; i < a.size(); i++)
            {
                if (a.find(a[i]) == i)
                {
                    res += a[i];
                }
            }
            cout << res << '\n';
        }
    }

    return 0;
}
