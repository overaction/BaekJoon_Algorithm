#include <iostream>
#include <vector>
#include <stdio.h>
#define INF 1000000001
using namespace std;

int N;
int maxans = -INF;
int minans = INF;
vector < int > nums;
// 0,1,2,3 == +,-,*,/
vector < int > beforeop;
vector < int > realop;
bool check[11];

void cal() {
    int result = nums[0];
    for(int i=0; i<realop.size(); i++) {
        int op = realop[i];
        switch(op) {
            case 0:
                result += nums[i+1];
                break;
            case 1:
                result -= nums[i+1];
                break;
            case 2:
                result *= nums[i+1];
                break;
            case 3:
                result /= nums[i+1];
                break;
        }
    }
    maxans = max(maxans, result);
    minans = min(minans, result);
}

void solution(int cnt) {
    if(cnt == N-1) {
        cal();
        return;
    }
    for(int i=0; i<beforeop.size(); i++) {
        if(!check[i]) {
            check[i] = true;
            realop.push_back(beforeop[i]);
            solution(cnt+1);
            realop.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    int num;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        nums.push_back(num);
    }
    for(int i=0; i<4; i++) {
        scanf("%d",&num);
        for(int j=0; j<num; j++) {
            beforeop.push_back(i);
        }
    }
    solution(0);
    printf("%d %d",maxans,minans);
}
