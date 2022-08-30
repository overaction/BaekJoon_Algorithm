#include <iostream>
#include <stdio.h>
#include <deque>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N,M,K;
int A[11][11];
int E[11][11];
int dy[8] = {-1,1,0,0,1,-1,1,-1};
int dx[8] = {0,0,-1,1,-1,1,1,-1};
vector < int > v[11][11];

void future() {
    int vsize;
    int treeToEnergy = 0;
    int y,x,year;
    // 봄,여름
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            vsize = v[i][j].size();
            if(vsize == 0) continue;
            vector <int> temp;
            sort(v[i][j].begin(),v[i][j].end());
            for(int k=0; k<vsize; k++) {
                if(v[i][j][k] <= E[i][j]) {
                    E[i][j] -= v[i][j][k];
                    temp.push_back(v[i][j][k] + 1);
                }
                else {
                    treeToEnergy += v[i][j][k] / 2;
                }
            }
            v[i][j].clear();
            for(int k=0; k<temp.size(); k++) {
                v[i][j].push_back(temp[k]);
            }
            E[i][j] += treeToEnergy;
            treeToEnergy = 0;
        }
    }
    // 겨울, 가을
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            E[i][j] += A[i][j];
            vsize = v[i][j].size();
            if(vsize == 0) continue;
            for(int k=0; k<vsize; k++) {
                if(v[i][j][k] % 5 != 0) continue;
                for(int m=0; m<8; m++) {
                    int ny = i + dy[m];
                    int nx = j + dx[m];
                    if(ny > N || ny <= 0 || nx > N || nx <= 0) continue;
                    v[ny][nx].push_back(1);
                }
            }
        }
    }
}

int main() {
    int x,y,z;
    scanf("%d %d %d",&N,&M,&K);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&A[i][j]);
            E[i][j] = 5;
        }
    }
    for(int i=1; i<=M; i++) {
        scanf("%d %d %d",&y,&x,&z);
        v[y][x].push_back(z);
    }
    for(int i=1; i<=K; i++) {
        future();
    }
    int result = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            result += v[i][j].size();
        }
    }
    printf("%d",result);
}
