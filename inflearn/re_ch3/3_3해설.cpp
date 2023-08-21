#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

struct Student
{
    int n, p;
    char t;

    Student(int a, char b, int c)
    {
        n = a;
        t = b;
        p = c;
    }
    bool operator<(const Student &b) const
    {
        return p < b.p;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);

    int n;
    long long bsum = 0;
    cin >> n;

    vector<int> res(n);
    unordered_map<char, int> team;
    vector<Student> st;
    for (int i = 0; i < n; i++)
    {
        char a;
        int b;
        cin >> a >> b;
        st.push_back(Student(i, a, b));
    }

    sort(st.begin(), st.end());

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        for (; j < n; j++)
        {
            if (st[i].p > st[j].p)
            {
                bsum += st[j].p;
                team[st[j].t] += st[j].p;
            }
            else
                break;
        }
        res[st[i].t] = bsum - team[st[i].t];
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << '\n';
    }

    return 0;
}
