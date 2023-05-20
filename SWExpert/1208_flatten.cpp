#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{

    for (int tc = 0; tc < 10; tc++)
    {

        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;


        freopen("input (19).txt", "r", stdin);
        int cnt;
        cin >> cnt;

        for (int i = 0; i < 100; i++)
        {
            int a;
            cin >> a;
            minheap.push(a);
            maxheap.push(a);
        }

        for (int i = 0; i < cnt; i++)
        {
            if (minheap.top() + 1 <= 100)
            {
                minheap.push(minheap.top() + 1);
                minheap.pop();
            }
            if (maxheap.top() - 1 >= 1)
            {
                maxheap.push(maxheap.top() - 1);
                maxheap.pop();
            }
        }

        int result = maxheap.top() - minheap.top();

        cout << "#" << tc + 1 << " " << result << '\n';
    }

    return 0;
}
