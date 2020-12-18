#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
int K;
int wheel[5][9];
int original[5][9];
bool rotating[5][5];

// 1:30
int main() {
    int num,dir,nextdir;
    int before,after,temp;
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=8; j++) {
            scanf("%1d",&wheel[i][j]);
            original[i][j] = wheel[i][j];
        }
    }
    scanf("%d",&K);
    for(int r=1; r<=K; r++) {
        scanf("%d %d",&num,&dir);
        // �´��� �κ� �ľ�
        for(int i=1; i<=3; i++) {
            if(wheel[i][3] != wheel[i+1][7]) {
                rotating[i][i+1] = 1;
                rotating[i+1][i] = 1;
            }
        }
        // ��Ϲ����� �����ش�
        if(dir == 1) {
            for(int j=1; j<=7; j++) {
                wheel[num][j+1] = original[num][j];
            }
            wheel[num][1] = original[num][8];
        }
        else {
            for(int j=7; j>=1; j--) {
                wheel[num][j] = original[num][j+1];
            }
            wheel[num][8] = original[num][1];
        }
        while(1) {
            // ���ư� �������� �����ʿ� �ִ� �����鿡 ����
            nextdir = dir;
            bool possible = false;
            for(int k=num; k<=3; k++) {
                if(rotating[k][k+1]) {
                    // ���� �ٲ㼭����
                    nextdir = (nextdir == 1) ? -1 : 1;
                    // ��Ϲ����� �����ش�
                    if(nextdir == 1) {
                        for(int l=1; l<=7; l++) {
                            wheel[k+1][l+1] = original[k+1][l];
                        }
                        wheel[k+1][1] = original[k+1][8];
                    }
                    else {
                        for(int l=7; l>=1; l--) {
                            wheel[k+1][l] = original[k+1][l+1];
                        }
                        wheel[k+1][8] = original[k+1][1];
                    }
                }
                // �ȵ��ư��� �����ۿ� ���Ͼ
                else break;
            }
            // ����
            nextdir = dir;
            for(int k=num-1; k>=1; k--) {
                if(rotating[k+1][k]) {
                    // ���� �ٲ㼭����
                    nextdir = (nextdir == 1) ? -1 : 1;
                    // ��Ϲ����� �����ش�
                    if(nextdir == 1) {
                        for(int l=1; l<=7; l++) {
                            wheel[k][l+1] = original[k][l];
                        }
                        wheel[k][1] = original[k][8];
                    }
                    else {
                        for(int l=7; l>=1; l--) {
                            wheel[k][l] = original[k][l+1];
                        }
                        wheel[k][8] = original[k][1];
                    }
                }
                else break;
            }
            break;
        }
        // �ʱ�ȭ
        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                rotating[i][j] = 0;
            }
        }
        for(int i=1; i<=4; i++) {
            for(int j=1; j<=8; j++) {
                original[i][j] = wheel[i][j];
            }
        }
        // �´��� �κ� �ٽ� �ľ�
        for(int i=1; i<=3; i++) {
            if(wheel[i][3] != wheel[i+1][7]) {
                rotating[i][i+1] = 1;
                rotating[i+1][i] = 1;
            }
        }
    }
    int result = 0;
    for(int i=1; i<=4; i++) {
        if(i == 1 && wheel[i][1]) result += 1;
        else if(i==2 && wheel[i][1]) result += 2;
        else if(i==3 && wheel[i][1]) result += 4;
        else if(i==4 && wheel[i][1]) result += 8;
    }
    printf("%d",result);
}
