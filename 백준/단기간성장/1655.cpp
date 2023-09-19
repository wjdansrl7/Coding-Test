#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        if (maxHeap.size() <= minHeap.size())
        {
            maxHeap.push(x);

            if (!minHeap.empty() && maxHeap.top() > minHeap.top())
            {
                int a1 = minHeap.top();
                int a2 = maxHeap.top();
                minHeap.pop();
                maxHeap.pop();
                minHeap.push(a2);
                maxHeap.push(a1);
            }
            cout << maxHeap.top() << '\n';
        }
        else
        {
            minHeap.push(x);

            if (!minHeap.empty() && maxHeap.top() > minHeap.top())
            {
                int a1 = minHeap.top();
                int a2 = maxHeap.top();
                minHeap.pop();
                maxHeap.pop();
                minHeap.push(a2);
                maxHeap.push(a1);
            }
            cout << maxHeap.top() << '\n';
        }
    }

    return 0;
}