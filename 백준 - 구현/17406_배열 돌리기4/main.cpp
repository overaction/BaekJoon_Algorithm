#include <iostream>
#include <stdio.h>
#include <deque>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct option {
    int r,c,s;
};
int N,M,K;
int result = 987654321;
int Arr[51][51];
int original[51][51];
int selects[7];
vector < option > info;
vector < option > infos;

void reset_arr() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            Arr[i][j] = original[i][j];
        }
    }
}

void print() {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                printf("%d ",Arr[i][j]);
            }
            printf("\n");
        }
}

void moving() {
    for(int i=0; i<infos.size(); i++) {
        int r = infos[i].r;
        int c = infos[i].c;
        int s = infos[i].s;
        int topy = r-s;
        int topx = c-s;
        int bottomy = r+s;
        int bottomx = c+s;
        int temp[51][51];
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                temp[i][j] = Arr[i][j];
            }
        }
        while(1) {
            if(topy == bottomy) break;
            // 윗부분 3 1 5 3
            for(int i=topx+1; i<=bottomx; i++) {
                Arr[topy][i] = temp[topy][i-1];
            }
            // 오른쪽 부분
            for(int i=topy+1; i<=bottomy; i++) {
                Arr[i][bottomx] = temp[i-1][bottomx];
            }
            // 아랫부분
            for(int i=bottomx-1; i>=topx; i--) {
                Arr[bottomy][i] = temp[bottomy][i+1];
            }
            // 왼쪽 부분
            for(int i=bottomy-1; i>=topy; i--) {
                Arr[i][topx] = temp[i+1][topx];
            }
            // 좁혀들어가기
            topy += 1;
            topx += 1;
            bottomy -= 1;
            bottomx -= 1;
        }
    }
}

void selecting(int cnt) {
    if(cnt == K) {
        moving();
        // 계산
        int res = 987654321;
        for(int i=1; i<=N; i++) {
            int hap = 0;
            for(int j=1; j<=M; j++) {
                hap += Arr[i][j];
            }
            res = min(res,hap);
        }
        result = min(res,result);
        // 초기화
        reset_arr();
        return;
    }
    for(int i=1; i<=K; i++) {
        if(selects[i] == 0) {
            selects[i] = 1;
            int r = info[i-1].r;
            int c = info[i-1].c;
            int s = info[i-1].s;
            infos.push_back({r,c,s});
            selecting(cnt+1);
            infos.pop_back();
            selects[i] = 0;
        }
    }
}

int main()
{
    scanf("%d %d %d",&N,&M,&K);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&Arr[i][j]);
            original[i][j] = Arr[i][j];
        }
    }
    int r,c,s;
    for(int i=1; i<=K; i++) {
        scanf("%d %d %d",&r,&c,&s);
        info.push_back({r,c,s});
    }
    selecting(0);
    printf("%d",result);
}
