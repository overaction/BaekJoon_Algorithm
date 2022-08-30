#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define INF 987654321
using namespace std;
int N;
int board[100001][3];
int cache[2][3];
int cachem[2][3];

void solution() {
    for(int i=0; i<N; i++) {
        int now = (i+1)%2;
        int prev = (i)%2;
        cache[now][0] = max(cache[])
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d",&board[i][j]);
        }
    }
    int maximum = 0;
    int minimum = INF;
}
