#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
	stack <char> st;
	char now = s[0];
	st.push(now);
	for(int i=1; i<s.size(); i++) {
		st.push(s[i]);
		if(st.size() >= 2) {
			if(now == st.top()) {
				st.pop();
				st.pop();
			}
		}
		if(st.size() != 0) now = st.top();
	}
	if(st.size() == 0) answer = 1;
    return answer;
}

int main() {
	string s = "baabaa";
	solution(s);
}