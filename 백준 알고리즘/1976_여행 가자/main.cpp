#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
int N,M;
bool possible = true;
deque < int > cityq[201];
int travel[1001];
int visited[201];

void dfs(int n) {
    visited[n] = 1;
    for(int i=0; i<cityq[n].size(); i++) {
        int next = cityq[n][i];
        if(visited[next]) continue;
        dfs(next);
    }
}

int main()
{
    int num;
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&num);
            if(num) {
                cityq[i].push_back(j);
            }
        }
    }
    for(int i=1; i<=M; i++) {
        scanf("%d",&travel[i]);
    }
    dfs(travel[1]);
    for(int i=1; i<=M; i++) {
        if(!visited[travel[i]]) {
            possible = false;
            break;
        }
    }
    if(possible) printf("YES");
    else printf("NO");
}
