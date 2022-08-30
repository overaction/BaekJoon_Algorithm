#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;
int F,S,G,U,D;
// 識 F類, 跡ル G類, 鬼�� S類 U 機 D 棻遴
int visited[1000001];
int counts[1000001];
int result = 0;
deque < int > dq;

int moving(int idx) {
    int ds[2] = {U,-D};
    visited[idx] = 1;
    dq.push_back(idx);
    while(!dq.empty()) {
        int now = dq.front();
        if(now == G) return counts[now];
        dq.pop_front();
        for(int i=0; i<2; i++) {
            int next = now + ds[i];
            if(next > F || next <= 0) continue;
            if(visited[next]) continue;
            visited[next] = 1;
            counts[next] = counts[now] + 1;
            dq.push_back(next);
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
    int result = moving(S);
    if(result == -1) printf("use the stairs");
    else printf("%d",result);
}
