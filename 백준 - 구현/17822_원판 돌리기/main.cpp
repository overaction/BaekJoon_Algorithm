#include <iostream>
#include <stdio.h>
#include <deque>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,T;
int x,d,k;
vector < int > circle[51];

void print() {
    for(int i=1; i<=N; i++) {
        for(int j=0; j<circle[i].size(); j++) {
            printf("%d ",circle[i][j]);
        }
        printf("\n");
    }
}

void moving() {
    int counts = 1;
    int idx = x;
    while(1) {
        int temp[M];
        if(idx > N) break;
        // next 칸 만큼 회전
        int next = k % M;
        if(d == 0) {
            for(int i=0; i<circle[idx].size(); i++) {
                int tempIdx = (i+next) % M;
                temp[tempIdx] = circle[idx][i];
            }
            for(int i=0; i<M; i++) {
                circle[idx][i] = temp[i];
            }
        }
        else {
            for(int i=0; i<circle[idx].size(); i++) {
                int tempIdx = (i-next + M) % M;
                temp[tempIdx] = circle[idx][i];
            }
            for(int i=0; i<M; i++) {
                circle[idx][i] = temp[i];
            }
        }
        idx = x * ;
    }
}

void deleting() {
    int hap = 0;
    int cnt2 = 0;
    vector < pair < int,int > > temp;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<circle[i].size(); j++) {
            int now = circle[i][j];
            if(!now) continue;
            hap += now;
            cnt2++;
            int cnt = 0;
            int module1 = (j + 1) % M;
            int module2 = (j - 1 + M) % M;
            if(circle[i][module1] == now) {
                temp.push_back({i,module1});
                cnt++;
            }
            if(circle[i][module2] == now) {
                temp.push_back({i,module2});
                cnt++;
            }
            if(i-1 >= 1 && circle[i-1][j] == now) {
                temp.push_back({i-1,j});
                cnt++;
            }
            if(i+1 <= N && circle[i+1][j] == now) {
                temp.push_back({i+1,j});
                cnt++;
            }
            if(cnt > 0) temp.push_back({i,j});
        }
    }
    if(temp.size()) {
        for(int i=0; i<temp.size(); i++) {
            int y = temp[i].first;
            int x = temp[i].second;
            circle[y][x] = 0;
        }
    }
    // 만약 겹치는게 없다면
    else {
        double middle = hap / (double)cnt2;
        for(int i=1; i<=N; i++) {
            for(int j=0; j<circle[i].size(); j++) {
                if(circle[i][j] == 0) continue;
                if(circle[i][j] > middle) circle[i][j] -= 1;
                else if(circle[i][j] < middle) circle[i][j] += 1;
            }
        }
    }
}

int main()
{
    int num;
    scanf("%d %d %d",&N,&M,&T);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&num);
            circle[i].push_back(num);
        }
    }
    for(int i=1; i<=T; i++) {
        // x배수인 원판을 d = 0 시계 1 반시계 k칸 회전
        scanf("%d %d %d",&x,&d,&k);
        moving();
        deleting();
    }
    // 결과
    int result = 0;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<circle[i].size(); j++) {
            result += circle[i][j];
        }
    }
    printf("%d",result);
}
