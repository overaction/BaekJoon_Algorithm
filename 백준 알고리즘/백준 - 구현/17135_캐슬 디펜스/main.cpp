#include <iostream>
#include <stdio.h>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;
struct option {
    int y,x;
    bool alive;
};
int N,M,D;
int board[16][16];
bool selection[16];
int result = 0;
vector < option > enemy;
void defense(int index, int cnt) {
    if(cnt == 3) {
        int res = 0;
        // 궁수 저장
        vector < int > arc;
        for(int i=1; i<=M; i++) if(selection[i]) arc.push_back(i);
        // 원본대신 복사본으로
        vector < option > copy_enemy = enemy;
        while(1) {
            if(enemy.size() == 0) break;
            for(int i=0; i<arc.size(); i++) {
                int ay = N+1;
                int ax = arc[i];
                int targetx = M+1;
                int idx = -1;
                int dist = 98765432;
                for(int j=0; j<copy_enemy.size(); j++) {
                    int tempDist = abs(ay - copy_enemy[j].y) + abs(ax - copy_enemy[j].x);
                    if(tempDist > D) continue;
                    if(tempDist < dist) {
                        dist = tempDist;
                        targetx = copy_enemy[j].x;
                        idx = j;
                    }
                    else if(tempDist == dist && targetx > copy_enemy[j].x) {
                        targetx = copy_enemy[j].x;
                        idx = j;
                    }
                }
                if(idx != -1 && copy_enemy[idx].alive == true) {
                    copy_enemy[idx].alive = false;
                    res++;
                }
            }
            vector < option > temp;
            // 공격받은 적 제거, 한칸 위로 이동
            for(int i=0; i<copy_enemy.size(); i++) {
                if(copy_enemy[i].alive == true && copy_enemy[i].y+1 <= N) {
                    temp.push_back({copy_enemy[i].y+1,copy_enemy[i].x,true});
                }
            }
            if(temp.size() == 0) break;
            copy_enemy = temp;
        }
        result = max(result,res);
        return;
    }


    for(int i=index; i<=M; i++) {
        if(selection[i] == 0) {
            selection[i] = 1;
            defense(i,cnt+1);
            selection[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d %d",&N,&M,&D);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&board[i][j]);
            if(board[i][j]) enemy.push_back({i,j,true});
        }
    }
    defense(1,0);
    printf("%d",result);
}
