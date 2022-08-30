#include <iostream>
#include <deque>
#include <stdio.h>
using namespace std;
int N,M,u,v,cnt=0;
int graph[1001][1001];
int visited[1001];

deque < int > dq[1001];

void bfs(int v) {
    cnt++;
    visited[v] = 1;
    deque < int > q;
    q.push_back(v);
    while(!q.empty()) {
        int node = q.back();
        q.pop_back();
        int dqSize = dq[node].size();
        for(int i=0; i<dqSize; i++) {
            int next = dq[node][i];
            if(visited[next]) continue;
            visited[next] = 1;
            q.push_back(next);
        }
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
        if(visited[i] == 0)
            bfs(i);
    }
    printf("%d",cnt);
}
