#include <iostream>
#include <deque>
#include <stdio.h>
using namespace std;
int N,M,u,v,cnt=0;
int graph[1001][1001];
int visited[1001];

deque < int > dq[1001];

void dfs(int v) {
    visited[v] = 1;
    int dqSize = dq[v].size();
    for(int i=0; i<dqSize; i++) {
        int next = dq[v][i];
        if(visited[next] == 1) continue;
        dfs(next);
    }
}

int main()
{
    scanf("%d %d",&N,&M);
    for(int i=1; i<=M; i++) {
        scanf("%d %d",&u,&v);
        dq[u].push_back(v);
        dq[v].push_back(u);
    }
    for(int i=1; i<=N; i++) {
        if(visited[i] == 0) {
            dfs(i);
            cnt++;
        }
    }
    printf("%d",cnt);
}
