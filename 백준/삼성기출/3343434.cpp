#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int n, k, s;
    cin >> n >> k;
    vector<int> score(n + 1, 0);

    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
    }

    int a, b;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;

        double sum = 0;
        for (int j = a; j <= b; j++)
        {
            sum += score[j];
        }

        printf("%.2f\n", (sum / (b - a + 1)));
    }
    return 0;
}