#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int scores[8] = {0,3,2,1,0,1,2,3};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
	map<char, int> resultMap;

	for(int i=0; i<survey.size(); i++) {
		resultMap[survey[i][choices[i]/4]] += scores[choices[i]];
	}

	answer += resultMap['R'] >= resultMap['T'] ? "R" : "T";
	answer += resultMap['C'] >= resultMap['F'] ? "C" : "F";
	answer += resultMap['J'] >= resultMap['M'] ? "J" : "M";
	answer += resultMap['A'] >= resultMap['N'] ? "A" : "N";
    return answer;
}