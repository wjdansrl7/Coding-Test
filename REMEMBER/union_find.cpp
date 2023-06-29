#include <iostream>
#define MAX_SIZE 100001
using namespace std;

int root[MAX_SIZE];
int parent[MAX_SIZE];

int find(int x)
{
    // 루트 노드는 부모 노드 번호로 자기 자신을 가진다.
    if (root[x] == x)
    {
        return x;
    }
    else
    {
        // 각 노드의 부모 노드를 찾아 올라간다.
        // "경로 압축(Path Compression)"
        // find 하면서 만난 모든 값의 부모 노드를 root로 만든다.
        return root[x] = find(root[x]);
    }
}

void union(int x, int y)
{
    x = find(x);
    y = find(y);

    // root[y] = x;

    // 두 값의 root가 같으면(이미 같은 트리) 합치지 않는다.
    if (x == y)
    {
        return;
    }

    if (x < y)
    {
        root[y] = x;
    }
    else
    {
        root[x] = y;
    }
}
// 초기화
int main(int argc, char const *argv[])
{

    for (int i = 0; i < MAX_SIZE; i++)
    {
        parent[i] = i;
    }

    return 0;
}
}
