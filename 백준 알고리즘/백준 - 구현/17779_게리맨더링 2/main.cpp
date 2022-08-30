#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
// 2:15
int N;
int Arr[21][21];

int calculate(int y, int x, int d1, int d2, int num) {
    if(num == 5) {
        int hap = 0;

    }
}

void gary(int y, int x) {
    for(int i=1; i<=x-1; i++) {
        for(int j=1; j<=N-x; j++) {
            int d1 = i;
            int d2 = j;
            if(y+d1+d2 <= y || y+d1+d2 > N) continue;
            vector < int > v;
            // 5¹ø±¸¿ª
            calculate(y,x,d1,d2,5);
        }
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&Arr[i][j]);
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            gary(i,j);
        }
    }
}
