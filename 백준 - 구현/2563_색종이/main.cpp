#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;
int square[101][101];
int N;
int main()
{
    int x,y;
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        scanf("%d %d",&x,&y);
        for(int j=x; j<x+10; j++) {
            for(int k=y; k<y+10; k++) {
                square[j][k] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i=1; i<=100; i++) {
        for(int j=1; j<=100; j++) {
            if(square[i][j]) cnt++;
        }
    }
    printf("%d",cnt);
}
