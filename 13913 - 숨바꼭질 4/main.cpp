#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

#define MAX_SIZE 100000

int N,K;
int visited[MAX_SIZE+1];
int step[MAX_SIZE+1];

stack < int > answer;

void solution() {
    queue < pair < int,int > > q;
    q.push({N,0});
    visited[N] = 1;

    while(!q.empty()) {
        int now = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(now == K) {
            printf("%d\n",depth);
            answer.push(K);
            for(int i=0; i<depth; i++) {
                int prev = step[now];
                answer.push(prev);
                now = prev;
            }
            break;
        }

        if(now+1 <= MAX_SIZE && visited[now+1] == 0) {
            q.push({now+1,depth+1});
            visited[now+1] = 1;
            step[now+1] = now;
        }
        if(now*2 <= MAX_SIZE && visited[now*2] == 0) {
            q.push({now*2,depth+1});
            visited[now*2] = 1;
            step[now*2] = now;
        }
        if(now-1 >= 0 && visited[now-1] == 0) {
            q.push({now-1,depth+1});
            visited[now-1] = 1;
            step[now-1] = now;
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    solution();
    while(!answer.empty()) {
        int now = answer.top();
        answer.pop();
        printf("%d ",now);
    }
    return 0;
}