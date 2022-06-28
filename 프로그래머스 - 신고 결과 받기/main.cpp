#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

// 사용자 별 신고당한 횟수
map < string, int > reportCnt;
// 사용자 별 신고한 사용자 리스트
map < string, set < string > > reportList;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 0으로 초기화
	vector<int> answer(id_list.size(),0);
	
	for(string s: report) {
		int blankIdx = s.find(" ");
		string from = s.substr(0, blankIdx);
		string to = s.substr(blankIdx+1);

		if(reportList[from].find(to) == reportList[from].end()) {
			reportCnt[to]++;
			reportList[from].insert(to);
		} 
	}

	for(string s: id_list) {
		int res = 0;

		for(string str: reportList[s])
			if(reportCnt[str] >= k) res++;
		
		answer.push_back(res);
	}


    return answer;
}

int main() {
	// vector < string > te;
	// te.push_back("q21 5rt");
	// te.push_back("gewg g");
	// te.push_back(" ");
	// te.push_back("30j g");
	// for(string s: te) {
	// 	int blankIdx = s.find(" ");
	// 	string from = s.substr(0, blankIdx);
	// 	string to = s.substr(blankIdx+1);
	// 	cout << from << to << endl;
	// }

	// 사용자 별 신고당한 횟수
	map < string, int > re;
	map < int, int > re2;
	// 사용자 별 신고한 사용자 리스트
	map < string, set < string > > rep;

	rep["5"].insert("a");
	rep["5"].insert("a");
	rep["5"].insert("a");
	rep["6"].insert("b");
	rep["7"].insert("c");

	printf("%d\n",rep.size());
	printf("%d\n",rep.at(0));
	set<string>::iterator it;
}