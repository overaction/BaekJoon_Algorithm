#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

#define MAX_SIZE 100000+1

int N, K;
int visited[MAX_SIZE];

int bfs() {
    deque<int> dq;
    dq.push_back(N);
    visited[N] = 1;
    while (!dq.empty()) {
         // 덱의 앞의 요소들부터 꺼내옴
        int pos_x = dq.front();
        dq.pop_front();

        if(pos_x == K) return visited[K] - 1;

        // 순간이동은 덱의 앞쪽에 집어넣음.
        if (pos_x * 2 < MAX_SIZE && !visited[pos_x * 2]) {
            dq.push_front(pos_x * 2);
            visited[pos_x * 2] = visited[pos_x];
        }

        // 걷는이동은 덱의 뒤쪽에 집어넣음.
        if (pos_x + 1 < MAX_SIZE && !visited[pos_x + 1]) {
            dq.push_back(pos_x + 1);
            visited[pos_x + 1] = visited[pos_x] + 1;
        }

        // 걷는이동은 덱의 뒤쪽에 집어넣음.
        if (pos_x - 1 >= 0 && !visited[pos_x - 1]) {
            dq.push_back(pos_x - 1);
            visited[pos_x - 1] = visited[pos_x] + 1;
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d\n", bfs());
    return 0;
}