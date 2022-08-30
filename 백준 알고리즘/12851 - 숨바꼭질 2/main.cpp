#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N,K;
vector < bool > visitedV(100001, false);

void solution(int start) {
    int time = 987654321; 
    int cnt = 0;
    queue < pair < int,int > > q;
    q.push({start,0});
    visitedV[start] = true;

    while(!q.empty()) {
        int now = q.front().first;
        int depth = q.front().second;
        q.pop();
        visitedV[now] = true;

        if(time < depth) break;
        if(now == K) {
            time = depth;
            cnt++;
            continue;
        }

        if(now-1 >= 0 && !visitedV[now-1]) q.push({now-1, depth+1});
        if(now+1 <= 100000 && !visitedV[now+1]) q.push({now+1, depth+1});
        if(now*2 <= 100000 && !visitedV[now*2]) q.push({now*2, depth+1});
    }
    printf("%d\n%d",time,cnt);
}

int main() {
    scanf("%d %d",&N,&K);
    solution(N);
    
}