#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;

string s;
stack < char > op;

void solution() {
    for(int i=0; i<s.size(); i++) {
        if(s[i] != '*' && s[i] != '/' && s[i] != '+' && s[i] != '-' && s[i] != '(' && s[i] != ')') {
            printf("%c",s[i]);
        }
        else {
            if(s[i] == '(')
                op.push(s[i]);
            else if(s[i] == '*' || s[i] == '/') {
                while(!op.empty() && (op.top() == '*' || op.top() == '/')) {
                    printf("%c",op.top());
                    op.pop();
                }
                op.push(s[i]);
            }
            else if(s[i] == '+' || s[i] == '-') {
                while(!op.empty() && (op.top() != '(')) {
                    printf("%c",op.top());
                    op.pop();
                }
                op.push(s[i]);
            }
            else if(s[i] == ')') {
                while(!op.empty() && (op.top() != '(')) {
                    printf("%c",op.top());
                    op.pop();
                }
                op.pop();
            }
        }
    }
    while(!op.empty()) {
        printf("%c",op.top());
        op.pop();
    }
}

int main() {
    cin >> s;
    solution();
}