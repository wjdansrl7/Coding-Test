#include <iostream>
#include <string>

using namespace std;

// TODO: basic_string substr(size_type pos = 0, size_type count = npos) const;
// pos: 첫 번째 문자의 위치
// count : 부분 문자열의 길이
int main(int argc, char const *argv[])
{
    string a = "0123456789abcdefghij";

    // count가 npos이므로 pos 부터 문자열 끝까지 리턴한다.
    string sub1 = a.substr(10);
    cout << sub1 << '\n';

    // pos 와 pos + count 모두 문자열 범위 안이므로, 해당하는 부분 문자열을
    // 리턴한다.
    string sub2 = a.substr(5, 3);
    cout << sub2 << '\n';

    // pos는 문자열 범위 안이지만, post + count는 밖이므로 pos부터 문자열 끝까지
    // 리턴한다.
    string sub4 = a.substr(a.size() - 3, 50);
    cout << sub4 << '\n';

    try
    {
        // pos 가 문자열 범위 밖이므로 예외를 발생시킴.
        string sub5 = a.substr(a.size() + 3, 50);
        cout << sub5 << '\n';
    }
    catch (const out_of_range &e)
    {
        cout << "pos exceeds string size\n";
    }

    return 0;
}
