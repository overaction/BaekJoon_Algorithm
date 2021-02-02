#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_INING 51
int N,answer=0;
int baseb[MAX_INING][10];
bool select[10];
int order[10];

void simulate() {
    int score = 0;
    int start = 1;
    int base[4];
    for(int i=1; i<=N; i++) {
        int outCnt = 0;
        bool nextIning = false;
        while(1) {
            for(int j=start; j<10; j++) {
                int player = baseb[i][order[j]];
                switch(player) {
                case 0:
                    outCnt++;
                    break;
                case 1:
                    for(int b=3; b>=1; b--) {
                        if(base[b]) {
                            if(b == 3) {
                                base[b] = 0;
                                score++;
                            }
                            else {
                                base[b+1] = 1;
                                base[b] = 0;
                            }
                        }
                    }
                    base[1] = 1;
                    break;
                case 2:
                    for(int b=3; b>=1; b--) {
                        if(base[b]) {
                            if(b == 3 || b == 2) {
                                base[b] = 0;
                                score++;
                            }
                            else {
                                base[b+2] = 1;
                                base[b] = 0;
                            }
                        }
                    }
                    base[2] = 1;
                    break;
                case 3:
                    for(int b=3; b>=1; b--) {
                        if(base[b] == 1) {
                            base[b] = 0;
                            score++;
                        }
                    }
                    base[3] = 1;
                    break;
                case 4:
                    for(int b=3; b>=1; b--) {
                        if(base[b] == 1) {
                            base[b] = 0;
                            score++;
                        }
                    }
                    score++;
                }
                if(outCnt == 3) {
                    start = j+1;
                    if(start == 10) start = 1;
                    nextIning = true;
                    break;
                }
            }
            // 만약 3아웃으로 다음이닝으로 넘어간다면 진행
            // 아니고 한바퀴 더 돌아야 한다면 첫 타자부터 다시 진행
            if(nextIning) break;
            start = 1;
        }
        memset(base,0,sizeof(base));
    }
    answer = max(answer,score);
}

void DFS(int cnt) {
    if(cnt == 10) {
        simulate();
        return;
    }
    for(int i=1; i<10; i++) {
        if(select[i]) continue;
        select[i] = true;
        order[i] = cnt;
        DFS(cnt+1);
        select[i] = false;
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=9; j++) {
            scanf("%d",&baseb[i][j]);
        }
    }
    select[4] = true;
    order[4] = 1; // 4번타자에 1번선수 고정
    DFS(2);
    printf("%d",answer);
}
