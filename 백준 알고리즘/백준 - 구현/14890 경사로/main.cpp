#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int N,L;
int road[101][101];
int reverseRoad[101][101];

int angle(int R[][101]) {
    int total = 0;
    for(int i=1; i<=N; i++) {
        bool possible = true;
        int before = 1;
        for(int j=1; j<=N-1; j++) {
            // �� ���� ���̰� ���ٸ�
            if(R[i][j] == R[i][j+1])
                before++;
            // ���� ���̰� ���� ���̺��� 1 ���ٸ�
            else if(R[i][j] == R[i][j+1] + 1) {
                int height = R[i][j+1];
                for(int k = j+1; k < j+1+L; k++) {
                    if(height != R[i][k]) {
                        possible = false;
                        break;
                    }
                }
                if(!possible) break;
                // ���� j �� ���� ���κ�
                j = j + L - 1;
                // ���� ������ �ʱ�ȭ
                before = 0;
            }
            // ���� ���̺��� ���� ���̰� 1 ���ٸ�
            else if(R[i][j] + 1 == R[i][j+1]) {
                if(before >= L) {
                    before = 1;
                }
                else {
                    possible = false;
                    break;
                }
            }
            // ���̰� 2 �̻��̶��
            else if(abs(R[i][j] - R[i][j+1]) >= 2) {
                possible = false;
                break;
            }
        }
        if(possible == true)
            total++;
    }
    return total;
}

int main()
{
    scanf("%d %d",&N,&L);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&road[i][j]);
            reverseRoad[j][i] = road[i][j];
        }
    }
    int A = angle(road);
    int B = angle(reverseRoad);
    printf("%d",A+B);
}
