#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <regex>
using namespace std;

int solution(string s) {
    int answer = s.size();

	for(int i=1; i<=s.size()/2; i++) {
		string temp = "";
		string check = s.substr(0,i);
		int cnt = 1;
		for(int j=i; j<=s.size(); j+=i) {
			if(check == s.substr(j,i)) cnt+=1;
			else {
				if(cnt == 1) temp += check;
				else temp += (to_string(cnt) + check);

				check = s.substr(j,i);
				cnt = 1;
			}
		}
		// 나머지 부분 추가
		if(s.size() % i != 0) temp += s.substr((s.size()/i)*i);
		
		if(answer > temp.size()) answer = temp.size();
	}
	return answer;
}

int main() {
	solution("aabbaccc");
}