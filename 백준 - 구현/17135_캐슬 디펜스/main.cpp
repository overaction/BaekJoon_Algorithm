#include <iostream>
#include <stdio.h>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct option {
    int y,x;
    bool alive;
}option;
int N,M,D;
int result = 0;
int castle[16][16];
bool selects[16];
vector < option > enemy;

void archer(int index, int cnt) {
    if(cnt == 3) {
        int res = 0;
        vector < option > temp;
        temp = enemy;
        // 궁수 배치
        vector < int > arc;
        for(int i=1; i<=M; i++) if(selects[i]) arc.push_back(i);
        while(1) {
            if(temp.size() == 0) break;
            // 각각 궁수에 대해
            for(int i=0; i<arc.size(); i++) {
                int idx = -1;
                int nowy = N+1;
                int nowx = arc[i];
                int targetx = M;
                int dist = 987654321;
                for(int j=0; j<temp.size(); j++) {
                    int tempDist = abs(nowy - temp[j].y) + abs(nowx - temp[j].x);
                    if(tempDist > D) continue;
                    if(dist > tempDist) {
                        targetx = temp[j].x;
                        dist = tempDist;
                        idx = j;
                    }
                    else if(dist == tempDist && targetx > temp[j].x) {
                        targetx = temp[j].x;
                        idx = j;
                    }
                }
                if(idx != -1 && temp[idx].alive == true) {
                    temp[idx].alive = false;
                    res++;
                }
            }
            vector < option > alives;
            for(int i=0; i<temp.size(); i++) {
                if(temp[i].alive) {
                    if(temp[i].y + 1 <= N) {
                        alives.push_back({temp[i].y+1,temp[i].x,temp[i].alive});
                    }
                }
            }
            if(alives.empty()) break;
            temp = alives;
        }
        result = max(result,res);
        return;
    }
    for(int i=index; i<=M; i++) {
        if(selects[i] == false) {
            selects[i] = true;
            archer(i,cnt+1);
            selects[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d %d",&N,&M,&D);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&castle[i][j]);
            if(castle[i][j]) enemy.push_back({i,j,true});
        }
    }
    archer(1,0);
    printf("%d",result);
}
