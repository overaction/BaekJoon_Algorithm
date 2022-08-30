#include <iostream>
#include <stdio.h>
#include <deque>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N,M;
deque < int > dq[501];
int visited[501];
int cnt = 0;

void friends() {
    deque < int > d;
    deque < int > nd;
    d.push_back(1);
    // 模备 炼荤
    while(!d.empty()) {
        int now = d.front();
        d.pop_front();
        for(int i=0; i<dq[now].size(); i++) {
            int next = dq[now][i];
            cnt++;
            visited[next] = 1;
            nd.push_back(next);
        }
    }
    // 模备狼 模备 炼荤
    while(!nd.empty()) {
        int now = nd.front();
        nd.pop_front();
        for(int i=0; i<dq[now].size(); i++) {
            int next = dq[now][i];
            if(visited[next]) continue;
            cnt++;
            visited[next] = 1;
        }
    }
}

int main()
{
    int a,b;
    scanf("%d %d",&N,&M);
    for(int i=1; i<=M; i++) {
        scanf("%d %d",&a,&b);
        dq[a].push_back(b);
        dq[b].push_back(a);
    }
    friends();
    printf("%d",cnt-1);
}
