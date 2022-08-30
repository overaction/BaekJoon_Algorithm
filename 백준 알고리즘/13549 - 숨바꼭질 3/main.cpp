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
bool visited[MAX_SIZE+1];

int solution() {
    priority_queue < pair < int,int >, vector < pair < int,int > >, greater < pair < int,int > > > q;
    q.push({0,N});
    visited[N] = true;
    
    while(!q.empty()) {
        int depth = q.top().first;
        int now = q.top().second;
        q.pop();

        if(now == K) {
            return depth;
        }

        if (now * 2 <= MAX_SIZE && !visited[now * 2]) {
            q.push({ depth, now * 2 });
            visited[now * 2] = true;
        }
        if (now + 1 <= MAX_SIZE && !visited[now + 1]) {
            q.push({ depth + 1, now + 1 });
            visited[now + 1] = true;
        }
        if (now - 1 >= 0 && !visited[now - 1]) {
            q.push({ depth + 1 , now - 1 });
            visited[now - 1] = true;
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d\n", solution());
    return 0;
}