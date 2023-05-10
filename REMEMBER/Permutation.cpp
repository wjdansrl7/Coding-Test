#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
Permutation(순열)
순열을 구할 데이터들은 정렬을 해줘야 한다.

library -> #include <algorithm>
오름차순 -> next_permutation
내림차순 -> prev_permutation

*/

int main(int argc, char const *argv[])
{
    string s = "1234";

    do
    {
        cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));

    cout << "\n\n";

    vector<int> v = {10, 5, 1, 2, 4};

    int len = v.size();

    sort(v.begin(), v.end()); //  정렬 후 next_permutation 사용해야 함

    do
    {
        for (int i = 0; i < len; i++)
        {
            cout << v[i] << " ";
        }
        cout << '\n';

    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
