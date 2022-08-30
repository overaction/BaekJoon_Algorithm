#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;
int N,K;
int value[11];

int solution() {
    int idx = 0;
    int cnt = 0;
    for(int i=N-1; i>=0; i--) {
        cnt += K / value[i];
        K = K % value[i];
    }
    return cnt;
}

int main()
{
    int num;
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++) {
        scanf("%d",&value[i]);
    }
    printf("%d\n",solution());
}
