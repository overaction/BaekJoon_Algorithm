#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque <string> dcity;
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for(int i=0; i<cities.size(); i++) {
        
        string now = cities[i];
        // 소문자변환
        for(int j=0; j<now.size(); j++) {
            now[j] = tolower(now[j]);
        }
        
        int idx = 0;
        bool hit = false;
        // hit인지 체크
        for(; idx < dcity.size(); idx++) {
            if(now == dcity.at(idx)) {
                hit = true;
                break;
            }
        }
        dcity.push_back(now);
        // hit라면 기존값 삭제
        if(hit) {
            dcity.erase(dcity.begin() + idx);
            answer++;
        }
        // miss라면 캐시가 full일 때 맨 앞 삭제
        else {
            if(cacheSize < dcity.size()) dcity.pop_front();
            answer += 5;
        }
    }
    return answer;
}