#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;
int N,M;
int p1,p2;
int a,b;
deque < int > dq[101];
int visited[101];
int ans = -1;
void dfs(int p, int cnt) {
    visited[p] = 1;
    int qsize = dq[p].size();
    for(int i=0; i<qsize; i++) {
        int next = dq[p][i];
        if(next == p2) {
            ans = cnt;
            return;
        }
        if(visited[next]) continue;
        dfs(next,cnt+1);
    }
}

int main()
{
    scanf("%d",&N);
    scanf("%d %d",&p1,&p2);
    scanf("%d",&M);
    for(int i=1; i<=M; i++) {
        scanf("%d %d",&a,&b);
        dq[a].push_back(b);
        dq[b].push_back(a);
    }
    dfs(p1,1);
    printf("%d",ans);
}
