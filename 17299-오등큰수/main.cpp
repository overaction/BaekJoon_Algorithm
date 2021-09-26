#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N;
vector < int > v;
stack < int > stNum;
stack < int > stCnt;
int counting[1000001];
int answer[1000001];

void solution() {
    for(int i=N-1; i>=0; i--) {
        int now = v[i];
        int nowCounts = counting[now];

        if(stCnt.empty()) {
            answer[i] = -1;
            stNum.push(now);
            stCnt.push(nowCounts);
        }
        else {
            while(!stCnt.empty()) {
                if(nowCounts >= stCnt.top()) {
                    stCnt.pop();
                    stNum.pop();
                }
                else {
                    answer[i] = stNum.top();
                    stNum.push(now);
                    stCnt.push(nowCounts);
                    break;
                }
            }
            if(stCnt.empty()) {
                answer[i] = -1;
                stNum.push(now);
                stCnt.push(nowCounts);
            }
        }
    }
}

int main() {
    int num;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        v.push_back(num);
        counting[num]++;
    }
    solution();
    for(int i=0; i<N; i++)
        printf("%d ",answer[i]);
}