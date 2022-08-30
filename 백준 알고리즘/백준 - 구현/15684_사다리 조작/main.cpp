#include <iostream>
#include <stdio.h>
#include <deque>
#include <string>
#include <vector>
using namespace std;
int N,M,H,result = 98765432;
int A[31][11];

void print() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=H; j++) {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}

int solution() {
    bool possible = true;
    for(int i=1; i<=N; i++) {
        int current = i;
        for(int j=1; j<=H; j++) {
            if(A[j][current]) current += 1;
            else if(A[j][current-1]) current -= 1;
        }
        if(current != i) {
            possible = false;
            break;
        }
    }
    return possible;
}

void DFS(int idx, int cnt) {
    if(cnt == 4) {
        return;
    }
    if(solution()) {
        result = (result > cnt) ? cnt : result;
        return;
    }
    // 사다리 세우기
    for(int i=idx; i<=H; i++) {
        for(int j=1; j<N; j++) {
            if(A[i][j-1]) continue;
            if(A[i][j]) continue;
            if(A[i][j+1]) continue;
            A[i][j] = 1;
            DFS(i,cnt+1);
            A[i][j] = 0;
        }
    }
}

int main()
{
    int a,b;
    scanf("%d %d %d",&N,&M,&H);
    for(int i=0; i<M; i++) {
        scanf("%d %d",&a,&b);
        A[a][b] = 1;
    }
    DFS(1,0);
    result == 98765432 ?printf("-1") : printf("%d",result);
}
