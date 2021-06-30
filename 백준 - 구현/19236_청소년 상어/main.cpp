#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int answer = 0;

typedef struct FISH {
    int y,x,dir,live;
}FISH;

FISH Fish[16];
int Map[5][5];

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void copy_state(int A[][5], int B[][5], FISH C[], FISH D[]) {
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=4; j++) {
            A[i][j] = B[i][j];
        }
    }
    for(int i=1; i<=16; i++) C[i] = D[i];
}

void move_Fish() {
    for(int i=1; i<=16; i++) {
        // ���� ������ �н�
        if(Fish[i].live == false) continue;

        int dir = Fish[i].dir;
        int y = Fish[i].y;
        int x = Fish[i].x;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        bool flag = false;
        // ������ ���
        if(ny > 4 || ny <= 0 || nx > 4 || nx <= 0) continue;
        // ���� ���ڸ����
        if(Map[ny][nx] == 0) {
            flag = true;
            Map[ny][nx] = i;
            Map[y][x] = 0;
            Fish[i].y = ny;
            Fish[i].x = nx;
        }
        // ���� �ٸ�����Ⱑ �ִٸ� �ڸ� �ٲٱ�
        else if(Map[ny][nx] != -1) {
            flag = true;

            swap(Map[y][x], Map[ny][nx]);

            FISH temp = Fish[i];
            int otherDir = Map[ny][nx];
            Fish[i].y = Fish[otherDir].y;
            Fish[i].x = Fish[otherDir].x;
            Fish[otherDir].y = temp.y;
            Fish[otherDir].x = temp.x;
        }

        // ������ 7���� Ž��
        if(flag == false) {
            int nDir = dir -= 1;
            if(nDir == 0) nDir = 8;
            while(nDir != dir) {
                int ny = y + dy[nDir];
                int nx = x + dx[nDir];
                if(ny <= 4 || ny > 0 || nx <= 4 || nx > 0) {
                    if(Map[ny][nx] == 0) {
                        Fish[i].y = ny;
                        Fish[i].x = nx;
                        Map[ny][nx] = i;
                        Map[y][x] = 0;
                        Fish[i].dir = nDir;
                        break;
                    }
                    else if(Map[ny][nx] != -1) {
                        swap(Map[ny][nx],Map[y][x]);
                        FISH temp = Fish[i];
                        int otherDir = Map[ny][nx];
                        Fish[i].y = Fish[otherDir].y;
                        Fish[i].x = Fish[otherDir].x;
                        Fish[otherDir].y = temp.y;
                        Fish[otherDir].x = temp.x;
                        Fish[i].dir = nDir;
                        break;
                    }
                }
                nDir -= 1;
                if(nDir == 0) nDir = 8;
            }
        }
    }
}

void DFS(int y, int x, int dir, int sum) {
    // �ִ� ����
    answer = max(answer,sum);
    // ���� ���� �ӽ� ����
    int copy_Map[5][5];
    FISH copy_Fish[16];
    copy_state(copy_Map,Map,copy_Fish,Fish);
    // ����� �����̱�
    move_Fish();
    // ��� �����̱�, *�ִ� 3ĭ�ۿ� ������ �� ����
    for(int i=1; i<=3; i++) {
        int ny = y + dy[dir] * i;
        int nx = x + dx[dir] * i;
        // ������ ����� break
        if(ny > 4 || ny <= 0 || nx > 4 || nx <= 0) break;
        if(Map[ny][nx] == 0) continue;
        int Fish_num = Map[ny][nx];
        int nDir = Fish[Fish_num].dir;
        // ���� ����
        Map[y][x] = 0;
        Map[ny][nx] = -1;
        Fish[Fish_num].live = false;
        // ���
        DFS(ny,nx,nDir,sum+Fish_num);
        // ���󺹱�
        Map[y][x] = -1;
        Map[ny][nx] = 0;
        Fish[Fish_num].live = true;
    }

    copy_state(Map,copy_Map,Fish,copy_Fish);
}

int main() {
    int a,b;
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=4; j++) {
            scanf("%d %d",&a,&b);
            Map[i][j] = a;
            Fish[a] = {i,j,b,true};
        }
    }
    // ��� �ʱⰪ
    int firstFish = Map[1][1];
    int firstDir = Fish[firstFish].dir;
    // ù ����� ����
    Fish[firstFish].live = false;
    // ��� ��ġ�� -1
    Map[1][1] = -1;
    // ����
    DFS(1,1,firstDir,firstFish);
    printf("%d\n",answer);
}
