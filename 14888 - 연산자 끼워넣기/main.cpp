#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define INF 1000000001
int N;
int maximum = -INF;
int minimum = INF;
int nums[11];
vector < int > opsV;
vector < int > nowV;
bool used[11];

void calculation() {
    int hap = nums[0];
    for(int i=0; i<N-1; i++) {
        switch(nowV[i]) {
            case 0:
                hap += nums[i+1];
                break;
            case 1:
                hap -= nums[i+1];
                break;
            case 2:
                hap *= nums[i+1];
                break;
            case 3:
                hap /= nums[i+1];
        }
    }
    maximum = (hap >= maximum) ? hap : maximum;
    minimum = (hap <= minimum) ? hap : minimum; 
}

void solution(int cnt) {
    if(cnt == N-1) {
        calculation();
    }
    for(int i=0; i<N-1; i++) {
        if(used[i] == false) {
            used[i] = true;
            nowV.push_back(opsV[i]);
            solution(cnt+1);
            nowV.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int op;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&nums[i]);
    }
    for(int i=0; i<4; i++) {
        scanf("%d",&op);
        for(int j=0; j<op; j++) {
            opsV.push_back(i);
        }
    }
    solution(0);
    printf("%d\n",maximum);
    printf("%d\n",minimum);
}