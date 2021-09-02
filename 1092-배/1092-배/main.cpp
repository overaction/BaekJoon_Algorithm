#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector < int > crain;
vector < int > box;
int answer = 0;

void solution() {
    // 다 넣을 수 없는경우
    if(crain[0] < box[0])
        return;
    // 박스를 전부 넣을때까지 반복
    while(!box.empty()) {
        int crainIdx = 0;
        for(int i=0; i<box.size(); i++) {
            // 크레인 순회를 마침
            if(crainIdx == crain.size())
                break;
            // 현재 크레인이 박스를 들 수 있다
            if(crain[crainIdx] > box[i]) {
                crainIdx++;
                box.erase(box.begin() + i);
                i -= 1;
            }
        }
        answer++;
    }
}

int main()
{
    int num;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        crain.push_back(num);
    }
    scanf("%d",&M);
    for(int i=0; i<M; i++) {
        scanf("%d",&num);
        box.push_back(num);
    }
    // 내림차순 정렬
    sort(crain.begin(),crain.end(), greater<int>());
    sort(box.begin(),box.end(),greater<int>());

    solution();
    printf("%d",answer);
}
