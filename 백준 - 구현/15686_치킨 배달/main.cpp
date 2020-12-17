#include <iostream>
#include <stdio.h>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N,M,result=98765432;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};
int chickens[14];
int village[51][51];
deque < pair < int,int > > chic;
deque < pair < int,int > > house;
void dfs(int cnt,int close,int idx) {
    if(cnt == close) {
        // 체크된 치킨집 폐업, 살아남은 치킨집 저장
        deque < pair < int,int > > alive;
        int y,x;
        for(int i=0; i<chic.size(); i++) {
            if(chickens[i]) {
                y = chic[i].first;
                x = chic[i].second;
                alive.push_back(make_pair(y,x));
            }
        }
        // 치킨거리 계산
        int sum = 0;
        for(int j=0; j<house.size(); j++) {
            int hy = house[j].first;
            int hx = house[j].second;
            int dist = 987654;
            for(int k=0; k<alive.size(); k++) {
                int cy = alive[k].first;
                int cx = alive[k].second;
                dist = min((abs(hy-cy)+abs(hx-cx)),dist);
            }
            sum += dist;
        }
        if(result > sum)
            result = sum;
        return;
    }
    for(int i=idx; i<chic.size(); i++) {
        if(!chickens[i]) {
            chickens[i] = 1;
            dfs(cnt+1,close,i+1);
        }
        chickens[i] = 0;
    }
}

int main()
{
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&village[i][j]);
            if(village[i][j] == 2) chic.push_back(make_pair(i,j));
            if(village[i][j] == 1) house.push_back(make_pair(i,j));
        }
    }
    for(int i=1; i<=M; i++) {
        dfs(0,i,0);
        // 초기화
        for(int i=0; i<chic.size(); i++)
            chickens[i] = 0;
    }
    printf("%d",result);
}
