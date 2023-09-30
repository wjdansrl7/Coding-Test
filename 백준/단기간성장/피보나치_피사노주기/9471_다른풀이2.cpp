#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int p;
    cin >> p;

    while (p--)
    {
        int num, m;
        cin >> num >> m;

        // 피보나치 만들기
        vector<int> fibonaci;
        fibonaci.push_back(0);
        fibonaci.push_back(1);

        // 새로 피보나치를 꼐속 갱신하면서 나머지를 찾는다.
        int n = 2;
        while (1)
        {
            fibonaci.push_back((fibonaci[n - 2] + fibonaci[n - 1]) % m);
            if (fibonaci[n - 1] % m == 0 && fibonaci[n] % m == 1)
            {
                break;
            }
            n++;
        }
        cout << num << " " << n - 1 << '\n';
    }

    return 0;
}
