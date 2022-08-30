#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int g,p;
// 각 노드마다 루트값을 저장
int gate[100001];
bool checked[100001];

int finding(int x) {
    if(x == gate[x]) return x;
    gate[x] = finding(gate[x]);
    return gate[x];
}

void unioning(int a, int b) {
    a = finding(a);
    b = finding(b);
    // 루트가 같다면 그냥 리턴
    if(a == b) return;
    // 아니라면 합침
    gate[a] = b;
}

int main()
{
    int gt;
    int cnt = 0;
    scanf("%d %d",&g,&p);

    // 처음엔 자기 자신이 부모 노드인 것으로 설정
    for(int i=0; i<=g; i++) gate[i] = i;

    for(int i=0; i<p; i++) {
        scanf("%d",&gt);

        int parent = finding(gt);
        // 도킹 가능한 게이트가 없음
        if(parent == 0)
            break;
        else {
            cnt++;
            unioning(parent, parent-1);
        }
    }
    printf("%d\n",cnt);
}
