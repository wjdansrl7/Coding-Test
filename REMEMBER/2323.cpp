#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a.at(1) > b.at(1);
    }
};

int main(int argc, char const *argv[])
{
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};

    for (auto job : jobs)
    {
        pq.push(job);
    }

    while (!pq.empty())
    {
        cout << pq.top()[0] << " " << pq.top()[1] << "\n";
        pq.pop();
    }

    return 0;
}
