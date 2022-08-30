#include <iostream>
#include <vector>
#include <stdio.h>
#define INF 1000000001
using namespace std;
int N;
vector < int > numV;
vector < int > opV;
vector < int > nowOpV;
bool check[10];
int minimum = INF;
int maximum = -INF;

int calculation() {
    int hap = numV[0];
    for(int i=0; i<nowOpV.size(); i++) {
        int nowOp = nowOpV[i];
        switch(nowOp) {
            case 0:
                hap += numV[i+1];
                break;
            case 1:
                hap -= numV[i+1];
                break;
            case 2:
                hap *= numV[i+1];
                break;
            case 3:
                hap /= numV[i+1];
                break;
        }
    }
    return hap;
}

void solution(int cnt) {
    if(cnt == N-1) {
        int result = calculation();
        maximum = (maximum < result) ? result : maximum;
        minimum = (minimum > result) ? result : minimum;
        return;
    }
    for(int i=0; i<N-1; i++) {
        if(check[i] == false) {
            check[i] = true;
            nowOpV.push_back(opV[i]);
            solution(cnt+1);
            nowOpV.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    int num;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        numV.push_back(num);
    }
    for(int i=0; i<4; i++) {
        scanf("%d",&num);
        for(int j=0; j<num; j++) {
            opV.push_back(i);
        }
    }
    solution(0);
    printf("%d %d",maximum,minimum);
}