#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool checking(string s) {
	stack <char> st;
	for(int i=0; i<s.size(); i++) {
		if(st.empty()) st.push(s[i]);
		else if(st.top() == '(' && s[i] == ')') st.pop();
		else st.push(s[i]);
	}
	if(st.size() != 0) return false;
	else return true;
}

int dividing(string s) {
	int cnt1 = 0, cnt2 = 0;
	for(int i=0; i<s.size(); i++) {
		if(s[i] == '(') cnt1++;
		else cnt2++;
		if(cnt1 == cnt2) return i;
	}
}

string dfs(string s) {
	// 1. 빈 문자인지 체크
	if(s.size() == 0) return "";
	// 2. 문자열 분할
	string u,v;
	int idx = dividing(s);
	u = s.substr(0,idx+1);
	v = s.substr(idx+1);

	// 3. u가 올바른 괄호 문자열이라면 v에 대해 1단계부터 시작
	// 3-1. 결과를 u에 붙여서 반환
	if(checking(u)) return u += dfs(v);
	// 4. u가 올바른 괄호 문자열이 아니면 문자열 생성해서 반환
	else {
		string temp = "(";
		temp += dfs(v);
		temp += ")";
		// u의 첫번째,마지막을 제거하고 뒤집은 결과 붙이기
		if(u.size() > 2) for(int i=1; i<u.size()-1; i++) temp += (u[i] == '(') ? ')' : '(';
		
		return temp;
	}
}

string solution(string p) {
    string answer = "";
	if(checking(p)) return answer;
	answer = dfs(p);
    return answer;
}

int main() {
	string s = "(((())))()";
	solution(s);
}