#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define INF 98765432
using namespace std;
int N,M;

int counting(vector < vector <int> > &board, int y, int x) {
    int cnt1=0,cnt2=0;
    for(int i=y; i<y+8; i++) {
        for(int j=x; j<x+8; j++) {
            // x,y 좌표 더한값이 짝수인 경우
            if((i+j) % 2 == 0) {
                // cnt1 : 첫 블록이 white인 경우의 바꿔야 하는 블록의 개수
                // cnt2 : 첫 블록이 black인 경우의 바꿔야 하는 블록의 개수
                if(board[i][j] == 1) cnt1++;
                else cnt2++;
            }
            else {
                if(board[i][j] == 0) cnt1++;
                else cnt2++;
            }
        }
    }
    int result = INF;
    result = min(result, cnt1);
    result = min(result, cnt2);
    return result;
}

int solution(vector < vector <int> > &board) {
    int result = INF;
    // 움직일 수 있는 경우의수
    for(int i=0; i<=N-8; i++) {
        for(int j=0; j<=M-8; j++) {
            int cnt = counting(board,i,j);
            result = min(cnt,result);
        }
    }
    return result;
}

int main()
{
    scanf("%d %d",&N,&M);
    vector < vector <int> > board(N, vector<int>(M,0));
    string s;
    for(int i=0; i<N; i++) {
        cin >> s;
        for(int j=0; j<M; j++) {
            if(s[j] == 'B') board[i][j] = 1;
        }
    }
    int result = solution(board);
    printf("%d\n",result);
}
