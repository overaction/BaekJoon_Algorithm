#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int hap = 0;
    int idx = 0;
    queue < int > bridgeQ;
    while(1) {
        // 마지막 트럭
        if(idx == truck_weights.size()) {
            answer += bridge_length;
            break;
        }
        int nowWeight = truck_weights[idx];
        answer++;
        // 다리를 건널수 있음
        if(bridgeQ.size() == bridge_length) {
            hap -= bridgeQ.front();
            bridgeQ.pop();
        }
        // 다리에 다음 차가 진입 가능
        if(hap + nowWeight <= weight) {
            hap += nowWeight;
            bridgeQ.push(nowWeight);
            idx++;
        }
        // 더이상 진입 불가능 (한칸 밀어내기 위해 무게가 0인 가상의 트럭 추가)
        else bridgeQ.push(0);
    }
    return answer;
}