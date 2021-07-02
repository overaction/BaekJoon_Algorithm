#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <deque>
#include <algorithm>
using namespace std;
int N,ans = -1;

void moveAndMerge(vector < vector < int > > &board, int dir) {
    // ��
    deque < int > dq;
    if(dir == 0) {
        for(int x=0; x<N; x++) {
            for(int y=0; y<N; y++) {
                if(board[y][x]) dq.push_back(board[y][x]);
                board[y][x] = 0;
            }
            int idx = 0;
            while(!dq.empty()) {
                int num = dq.front();
                dq.pop_front();

                if(board[idx][x] == 0)
                    board[idx][x] = num;
                else if(board[idx][x] == num) {
                    board[idx][x] *= 2;
                    idx++;
                }
                else {
                    idx++;
                    board[idx][x] = num;
                }
            }
        }
    }
    // �Ʒ�
    if(dir == 1) {
        for(int x=0; x<N; x++) {
            for(int y=N-1; y>=0; y--) {
                if(board[y][x]) dq.push_back(board[y][x]);
                board[y][x] = 0;
            }

            int idx = N-1;
            while(!dq.empty()) {
                int num = dq.front();
                dq.pop_front();

                if(board[idx][x] == 0)
                    board[idx][x] = num;
                else if(board[idx][x] == num) {
                    board[idx][x] *= 2;
                    idx--;
                }
                else {
                    idx--;
                    board[idx][x] = num;
                }
            }
        }
    }
    // ����
    if(dir == 2) {
        for(int y=0; y<N; y++) {
            for(int x=0; x<N; x++) {
                if(board[y][x]) dq.push_back(board[y][x]);
                board[y][x] = 0;
            }
            int idx = 0;
            while(!dq.empty()) {
                int num = dq.front();
                dq.pop_front();

                if(board[y][idx] == 0)
                    board[y][idx] = num;
                else if(board[y][idx] == num) {
                    board[y][idx] *= 2;
                    idx++;
                }
                else {
                    idx++;
                    board[y][idx] = num;
                }
            }
        }
    }
    // ������
    if(dir == 3) {
        for(int y=0; y<N; y++) {
            for(int x=N-1; x >= 0; x--) {
                if(board[y][x]) dq.push_back(board[y][x]);
                board[y][x] = 0;
            }

            int idx = N-1;
            while(!dq.empty()) {
                int num = dq.front();
                dq.pop_front();

                if(board[y][idx] == 0)
                    board[y][idx] = num;
                else if(board[y][idx] == num) {
                    board[y][idx] *= 2;
                    idx--;
                }
                else {
                    idx--;
                    board[y][idx] = num;
                }
            }
        }
    }
}

void printboard(vector < vector < int > > &board) {
    printf("\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solution(vector < vector < int > > &board, int cnt) {
    // ������� : 5�� �̵����� ��� �ִ밪�� ���Ѵ�
    if(cnt == 5) {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                ans = max(ans,board[i][j]);
        return;
    }

    // ���
    int temp[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            temp[i][j] = board[i][j];

    // ��� ����� �� Ž��
    for(int dir=0; dir<4; dir++) {
        moveAndMerge(board,dir);
        solution(board,cnt+1);
        // ����
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                board[i][j] = temp[i][j];
    }
}



int main()
{
    scanf("%d",&N);
    vector < vector < int > >board(N, vector<int>(N,0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d",&board[i][j]);
        }
    }
/*
    moveAndMerge(board,0);
    printboard(board);
    moveAndMerge(board,1);
    printboard(board);
    moveAndMerge(board,2);
    printboard(board);
    moveAndMerge(board,3);
    printboard(board);
*/
    solution(board,0);
    printf("%d\n",ans);
}
