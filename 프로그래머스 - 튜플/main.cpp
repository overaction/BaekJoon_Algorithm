#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair <int,string> a, pair <int,string> b) {
	return a.first < b.first;
}

vector<int> solution(string s) {
    vector<int> answer;

	vector <pair <int,string> >tuple;
	string temp = "";
	int cnt = 0;
	for(int i=2; i<s.size()-1; i++) {
		// 문자가 숫자일 경우
		if(s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
			cnt++;
		}
		// 구분자일 경우
		else if(s[i] == ',') temp += s[i];
		// 닫는 괄호일 경우
		else if(s[i] == '}') {
			tuple.push_back({cnt,temp+','});
			cnt = 0;
			temp = "";
			i++;
		}
	}

	sort(tuple.begin(), tuple.end(), cmp);
	map < string, int > m;
	for(int i=0; i<tuple.size(); i++) {
		string now = tuple[i].second;
		string num = "";
		for(int j=0; j<now.size(); j++) {
			if(now[j] == ',' && m[num] == 0) {
				answer.push_back(stoi(num));
				m[num] = 1;
				break;
			}
			else if(now[j] == ',' && m[num] != 0) {
				num = "";
				continue;
			}
			num += now[j];
		}
	}
    return answer;
}

int main() {
	solution("{{20,111},{111}}");
}