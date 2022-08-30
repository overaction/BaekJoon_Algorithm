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
            // 앞 뒤의 높이가 같다면
            if(R[i][j] == R[i][j+1])
                before++;
            // 앞의 높이가 뒤의 높이보다 1 높다면
            else if(R[i][j] == R[i][j+1] + 1) {
                int height = R[i][j+1];
                for(int k = j+1; k < j+1+L; k++) {
                    if(height != R[i][k]) {
                        possible = false;
                        break;
                    }
                }
                if(!possible) break;
                // 다음 j 는 경사로 끝부분
                j = j + L - 1;
                // 이전 평지는 초기화
                before = 0;
            }
            // 앞의 높이보다 뒤의 높이가 1 높다면
            else if(R[i][j] + 1 == R[i][j+1]) {
                if(before >= L) {
                    before = 1;
                }
                else {
                    possible = false;
                    break;
                }
            }
            // 차이가 2 이상이라면
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
