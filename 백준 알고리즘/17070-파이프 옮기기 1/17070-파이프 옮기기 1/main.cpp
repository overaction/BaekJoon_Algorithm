#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define MOD 1000000
using namespace std;

// ����� ���� �׻� 1000000���� �۰ų� �����Ƿ� 0.1�ʾȿ� �ذ� ����

int N;
int flag = false;
int pipe[16][16];
int cache[16][16];

// �� �밢 �Ʒ�
int dy[3] = {0,1,1};
int dx[3] = {1,1,0};

int result = 0;

// dir : 0 1 2(���� �밢 ����)
// y,x ��ġ�� ���� �� ���� ���� �ϴ� ����� �� ��ȯ
// 0 1 2 ��ĭ �� ��������
void solution(int y, int x, int dir) {
    if(y == N-1 && x == N-1) {
        result++;
        return;
    }

    // �������� ������ ���
    if(dir == 0) {
        for(int i=0; i<2; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= N || nx >= N) continue;
            if(pipe[ny][nx] == 1) continue;
            // �밢������ ���� �߰����� üũ
            if(i == 1 && (pipe[y+1][x] == 1 || pipe[y][x+1] == 1)) continue;
            solution(ny,nx,i);
        }
    }
    // �������� �밢���� ���
    else if(dir == 1) {
        for(int i=0; i<3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= N || nx >= N) continue;
            if(pipe[ny][nx] == 1) continue;
            if(i == 1 && (pipe[y+1][x] == 1 || pipe[y][x+1] == 1)) continue;
            solution(ny,nx,i);
        }
    }
    // �������� ������ ���
    else if(dir == 2) {
        for(int i=1; i<3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= N || nx >= N) continue;
            if(pipe[ny][nx] == 1) continue;
            if(i == 1 && (pipe[y+1][x] == 1 || pipe[y][x+1] == 1)) continue;
            solution(ny,nx,i);
        }
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d",&pipe[i][j]);
        }
    }
    solution(0,1,0);
    printf("%d\n",result);
}
