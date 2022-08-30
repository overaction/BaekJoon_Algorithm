#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
int A[1001];
int choice[1001];
int cache[1001];

// start에서 시작하는 최대 증가 부분 수열 길이 반환
int solution(int start) {
    int &ret = cache[start];
    if(ret != -1) return ret;

    ret = 1;
    int bestNext = -1;
    for(int i=start+1; i<N; i++) {
        if(A[start] < A[i]) {
            if(ret < solution(i) + 1) {
                ret = solution(i) + 1;
                bestNext = i;
            }
        }
    }
    // start 다음 index는 bestNext
    choice[start] = bestNext;
    return ret;
}

void reconstruct(int start, vector < int > &seq) {
    if(start == -1) return;
    seq.push_back(A[start]);
    reconstruct(choice[start],seq);
}

int main()
{
    memset(cache,-1,sizeof(cache));
    memset(choice,-1,sizeof(choice));
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&A[i]);
    }
    int result = 0;
    int bestIdx = 0;
    for(int i=0; i<N; i++) {
        int temp = solution(i);
        if(result < temp) {
            result = temp;
            bestIdx = i;
        }
    }
    vector < int > seq;
    printf("%d\n",result);
    reconstruct(bestIdx,seq);
    for(int i=0; i<seq.size(); i++)
        printf("%d ",seq[i]);
}
