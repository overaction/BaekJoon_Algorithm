#include <iostream>
#include <stdio.h>
#include <deque>
#include <string.h>
using namespace std;
int N,result=0;
int endPoint = 0;
deque < pair < int, int > > dq[10001];
int visited[10001];

void dfs(int root, int value) {
    if(visited[root])
        return;
    visited[root] = 1;
    if(result < value) {
        result = value;
        endPoint = root;
    }
    int dqSize = dq[root].size();
    for(int i=0; i<dqSize; i++) {
        int next = dq[root][i].first;
        int nextValue = dq[root][i].second;
        dfs(next,value+nextValue);
    }
}

int main()
{
    scanf("%d",&N);
    int pn,cn,val;
    for(int i=1; i<=N-1; i++) {
        scanf("%d %d %d",&pn,&cn,&val);
        dq[pn].push_back(make_pair(cn,val));
        dq[cn].push_back(make_pair(pn,val));
    }
    dfs(1,0);
    result = 0;
    memset(visited,0,sizeof(visited));
    dfs(endPoint,0);
    printf("%d",result);
}
