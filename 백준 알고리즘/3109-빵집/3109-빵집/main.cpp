#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int R,C;
int A[10001][501];
int visited[10001][501];
// ������ ������ ��, ������, ������ �Ʒ� ������ Ž���ϱ� ������ greedy�ϰ� ã�� �� �ִ�
int dy[3] = {-1,0,1};
int dx[3] = {1,1,1};
int flag = false;
int answer = 0;

void solution(int y, int x) {
    visited[y][x] = 1;
    if(x == C-1) {
        flag = true;
        answer++;
        return;
    }

    for(int i=0; i<3; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny >= R || ny < 0) continue;
        if(visited[ny][nx] || A[ny][nx] == 1) continue;

        solution(ny,nx);
        if(flag) return;
    }
}

int main()
{
    string s;
    scanf("%d %d",&R,&C);
    for(int i=0; i<R; i++) {
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            if(s[j] == '.') A[i][j] = 0;
            else A[i][j] = 1;
        }
    }
    for(int i=0; i<R; i++) {
        flag = false;
        solution(i,0);
    }
    printf("%d\n",answer);
}
