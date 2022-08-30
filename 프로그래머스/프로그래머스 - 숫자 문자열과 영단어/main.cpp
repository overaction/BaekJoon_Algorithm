#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <regex>
using namespace std;

int solution(string s) {
    int answer = 0;
    map < string, int > numMap;
    numMap["zero"] = 0;
    numMap["one"] = 1;
    numMap["two"] = 2;
    numMap["three"] = 3;
    numMap["four"] = 4;
    numMap["five"] = 5;
    numMap["six"] = 6;
    numMap["seven"] = 7;
    numMap["eight"] = 8;
    numMap["nine"] = 9;

    string temp = "";
    vector < int > answerV;
    for(int i=0; i<s.size(); i++) {
        if(isdigit(s[i])) answerV.push_back(s[i]-48);
        else {
            temp += s[i];
            if(temp == "zero" || numMap[temp] != 0) {
                answerV.push_back(numMap[temp]);
                temp = "";
            }
        }
    }

    int op = 1;
    for(int i=answerV.size()-1; i>=0; i--) {
        answer += (answerV[i] * op);
        op *= 10;
    }
    return answer;
}

int main() {
	solution("one4seven8");
}