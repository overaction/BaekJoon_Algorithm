#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

// <경우, 스코어>
unordered_map <string, vector<int> > scoreMap;

void addCases(string *s, int score) {
    for(int i=0; i<16; i++) {
        int a = i;
        string temp = "";
        for(int j=3; j>=0; j--) {
            if(a <= 0 || a % 2 == 0) temp = "-" + temp;
            else temp = s[j] + temp;
            a /= 2;
        }
        scoreMap[temp].push_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string s[4], temp;
    int score;

    // 문자열 파싱 후 모든 경우의 수 제작해서 score 넣어주기
    for(int i=0; i<info.size(); i++) {
        string now = info[i];
        istringstream sst(now);
        sst >> s[0] >> s[1] >> s[2] >> s[3] >> score;
        addCases(s,score);
    }
    // map에 있는 항목마다 score 순서대로 정렬
    for(auto itr = scoreMap.begin(); itr != scoreMap.end(); itr++) {
        sort(itr->second.begin(), itr->second.end());
    }

    // query 파싱
    for(int i=0; i<query.size(); i++) {
        string now = query[i];
        string result;
        istringstream sst(now);
        sst >> s[0] >> temp >> s[1] >> temp >> s[2] >> temp >> s[3] >> score;
        result = s[0] + s[1] + s[2] + s[3];
        if(scoreMap[result].size() != 0) {
            auto pos = lower_bound(scoreMap[result].begin(), scoreMap[result].end(),score) - scoreMap[result].begin();
            answer.push_back(scoreMap[result].size() - pos);
        }
        else answer.push_back(0);
    }

    return answer;
}

int main() {
    string s[6];
    int score = 10;
    string ss = "abc def 123";
    istringstream iss("abc ccd 455");
    iss >> s[0] >> s[1] >> score;
    //addCases(s,score);
}