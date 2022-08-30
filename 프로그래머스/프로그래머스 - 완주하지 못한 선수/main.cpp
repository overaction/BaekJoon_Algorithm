#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
	unordered_map < string, int > p;
	for(int i=0; i<participant.size(); i++) {
		p[participant[i]] += 1;
	}
	for(int i=0; i<completion.size(); i++) {
		p[completion[i]] -= 1;
	}
	for(int i=0; i<participant.size(); i++) {
		if(p[participant[i]] > 0) {
			answer += participant[i];
			break;
		}
	}
    return answer;
}