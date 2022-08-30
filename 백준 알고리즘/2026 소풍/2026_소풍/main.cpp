#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int K,N,F;
bool friends[901][901];
int answer[901];

int friendPairing(bool isChecked, int cnt) {
    int firstFriend = -1;
    for(int i=1; i<=N; i++) {
        if(!isChecked[i]) {
            firstFriend = i;
            break;
        }
    }
    // K명을 선발했다면 종료
    if(cnt == K) {

    }
}

int main()
{
    bool isChecked[901];
    scanf("%d %d %d",&K,&N,&F);
    for(int i=0; i<F; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        friends[a][b] = 1;
        friends[b][a] = 1;
    }
}
