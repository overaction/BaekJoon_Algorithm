#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <regex>
using namespace std;

string solution(string new_id) {
    string answer = "";

	// 1단계
	for(int i=0; i<new_id.size(); i++) {
		if(new_id[i] >= 'A' && new_id[i] <= 'Z') {
			answer += (char)(new_id[i] + 32);
		}
		else answer += new_id[i];
	}
	// 2단계
	string temp = "";
	for(char c: answer) {
		if(isalpha(c) || isdigit(c) || c == '-' || c == '_' || c == '.') temp += c;
	}
	answer = temp;
	temp = "";
	// 3단계
	temp = answer;
	int cnt = 0;
	for(int i=1; i<temp.size(); i++) {
		if(temp[i-1] == '.' && temp[i-1] == temp[i]) {
			answer.erase(i-1-cnt,1);
			cnt++;
		} 
	}
	// 4단계
	if(answer[0] == '.') answer.erase(0,1);
	if(answer[answer.size()-1] == '.') answer.erase(answer.size()-1,1);
	// 5단계
	if(answer.size() == 0) answer = "a";
	// 6단계
	if(answer.size() >= 16) answer = answer.substr(0,15);
	if(answer[answer.size()-1] == '.') answer.erase(answer.size()-1,1);
	// 7단계
	while(answer.length() < 3) answer += answer.back();
    return answer;
}

int main() {
	solution("ab");
}