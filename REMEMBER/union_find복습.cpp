/*
Disjoint Set
- 서로 중복되지 않는 부분 집합들로 나눠진 원소들에 대한 정보를 저장하고 조작하는 자료구조

Disjoint Set = 서로소 집합 자료구조

Union-Find
Disjoint Set을 표현할 때 사용하는 알고리즘

Union-Find의 사용 예시
전체 집합이 있을 때 구성 원소들이 겹치지 않도록 분할(아래 참고*)하는 데 자주 사용된다.

Kruskal MST 알고리즘에서 새로 추가할 간선의 양끝 정점이 같은 집합에 속해 있는지(사이클 형성 여부 확인)에 대해 검사하는 경우
초기에 {0}, {1}, {2}, … {n} 이 각각 n+1개의 집합을 이루고 있다. 여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려는 경우
집합의 표현-백준1717번
어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 가입한 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하는 경우
친구 네트워크-백준4195번

*/

#include <iostream>
#define MAX_SIZE 100001
using namespace std;

int root[MAX_SIZE];
int rank[MAX_SIZE];
int nodeCount[MAX_SIZE];

int find(int x)
{
    // 루트 노드는 부모 노드 번호로 자기 자신을 가리킨다.
    if (root[x] == x)
    {
        return x;
    }
    else
    {
        // 각 노드의 부모 노드를 찾아 올라간다.
        // return find(root[x]);

        // 경로 압축(Path Compression)
        // find 하면서 만난 모든 값의 부모 노드를 root로 만든다.
        return root[x] = find(root[x]);
    }
}

void unionParent(int x, int y)
{
    // 각 원소가 속한 트리의 루트 노드를 찾는다.
    x = find(x);
    y = find(y);

    // root[y] = x;

    // union 연산 최적화

    // 두 값의 root가 같으면(이미 같은 트리) 합치지 않는다.
    if (x == y)
    {
        return;
    }

    // "union-by-rank 최적화"
    // 항상 높이가 더 낮은 트리를 높이가 높은 트리 밑에 넣는다. 즉 높이가 더 높은 쪽을 root로 삼음
    if (rank[x] < rank[y])
    {
        root[x] = y; // x의 root를 y로 변경
    }
    else
    {
        root[y] = x; // y의 root를 x로 변경

        if (rank[x] == rank[y])
        {
            root[x]++; // 만약 높이가 같다면 합친 후(x의 높이 + 1)
        }
    }
}

int main(int argc, char const *argv[])
{
    // 초기화
    for (int i = 0; i < MAX_SIZE; i++)
    {
        root[i] = i;
        rank[i] = 0;
        nodeCount[i] = 1;
    }

    return 0;
}
