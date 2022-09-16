#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    bool minus = false;
    int max = -2e9, min = 2e9;
    int now = 0;
    for(int i=0; i<s.size(); i++) {
        // 계산하기
        if(s[i] == ' ') {
            if(minus) now = stoi(temp) * -1;
            else now = stoi(temp);
            max = (max < now) ? now : max;
            min = (min > now) ? now : min;
            // 초기화
            temp = "";
            minus = false;
        }
        // 마이너스 판별
        else if(s[i] == '-') minus = true;
        // 숫자
        else temp += s[i];
    }
    // 마지막에 한번 더 계산
    if(minus) now = stoi(temp) * -1;
    else now = stoi(temp);
    max = (max < now) ? now : max;
    min = (min > now) ? now : min;

    answer += to_string(min);
    answer += " ";
    answer += to_string(max);
    return answer;
}