#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool checkPair(char c1, char c2) {
    if(c1 == '[' && c2 == ']') return true;
    if(c1 == '(' && c2 == ')') return true;
    if(c1 == '{' && c2 == '}') return true;
    return false;
}

bool checking(string s) {
    stack <char> st;
    for(int i=0; i<s.size(); i++) {
        char now = s[i];
        // 비어있으면 push
        if(st.empty()) st.push(now);
        // 짝이 맞으면 pop 아니면 push
        else {
            char top = st.top();
            bool check = checkPair(top,now);
            if(check) st.pop();
            else st.push(now);
        }
    }
    if(st.empty()) return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.size(); i++) {
        string temp = s.substr(i) + s.substr(0,i);
        if(checking(temp)) answer++;
    }
    return answer;
}

int main() {
    solution("[](){}");
}