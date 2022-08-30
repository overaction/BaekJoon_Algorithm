#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int E,S,M;

int main() {
    scanf("%d %d %d",&E,&S,&M);
    int cnt1 = 0,cnt2 = 0,cnt3 = 0;
    int answer = 0;
    while(1) {
        cnt1++;
        cnt2++;
        cnt3++;
        answer++;
        if(cnt1 == 16) cnt1 = 1;
        if(cnt2 == 29) cnt2 = 1;
        if(cnt3 == 20) cnt3 = 1;
        if(cnt1 == E && cnt2 == S && cnt3 == M)
            break;
    }
    printf("%d\n",answer);
}