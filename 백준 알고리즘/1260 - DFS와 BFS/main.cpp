#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N,M,V;
vector < int > mapV;
int map[1001][1001];
int visited[1001];

void DFS(int v) {
    visited[v] = 1;
    printf("%d ",v);
    for(int i=1; i<=N; i++) {
        if(map[v][i] && !visited[i]) DFS(i);
    }
}

void BFS(int v) {
    queue < int > q;
    q.push(v);
    visited[v] = 1;
    printf("%d ",v);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i=1; i<=N; i++) {
            if(map[now][i] && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

int main() {
    int a,b;
    scanf("%d %d %d",&N,&M,&V);
    for(int i=0; i<M; i++) {
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
        map[b][a] = 1;
    }
    DFS(V);
    reset();
    printf("\n");
    BFS(V);
}