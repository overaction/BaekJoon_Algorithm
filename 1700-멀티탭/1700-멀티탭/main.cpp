#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,K;
int order[101];
int plug[101];

void solution() {
    int answer = 0;
    for(int i=0; i<K; i++) {
        // 이미 꽂혀있나 확인
        bool isPlug = false;
        for(int j=0; j<N; j++) {
            if(plug[j] == order[i]) {
                isPlug = true;
                break;
            }
        }
        // 꽃혀있다면 계속해서 탐색
        if(isPlug) continue;

        // 빈공간 탐색
        for(int j=0; j<N; j++) {
            // 빈공간 발견
            if(plug[j] == 0) {
                isPlug = true;
                plug[j] = order[i];
                break;
            }
        }
        if(isPlug) continue;

        // 빈공간이 없을경우 꽂혀있는 기기 중
        // 앞으로 사용되지 않는 기기 또는 가장 나중에 사용될 기기 탐색
        int unplugIdx = -1;
        int idx = 0;
        bool unplagPossible = false;
        for(int j=0; j<N; j++) {
            int lastIdx = 0;
            for(int k=i+1; k<K; k++) {
                // 얼마나 나중에 사용될지 확인
                if(plug[j] == order[k]) {
                    lastIdx = k;
                    unplagPossible = true;
                    break;
                }
            }
            // 나중에 사용되지 않음
            if(unplagPossible == false) {
                plug[j] = order[i];
                answer++;
                break;
            }
            // 가장 나중에 사용되는것 업데이트
            if(lastIdx > unplugIdx) {
                unplugIdx = lastIdx;
                idx = j;
            }
        }
        if(unplagPossible) {
            plug[idx] = order[unplugIdx];
            answer++;
        }
    }
    printf("%d\n",answer);
}

int main()
{
    int a;
    scanf("%d %d",&N,&K);
    for(int i=0; i<K; i++) {
        scanf("%d",&order[i]);
    }
    solution();
}
