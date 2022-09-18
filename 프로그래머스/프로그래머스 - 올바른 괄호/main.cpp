#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack <char> st;
    for(int i=0; i<s.size(); i++) {
        char now = s[i];
        if(st.empty() || now == '(') st.push(now);
        else if(st.top() == '(' && now == ')') st.pop();
    }
    if(st.empty()) return true;
    else return false;
}