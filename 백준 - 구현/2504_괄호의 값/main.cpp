#include <iostream>
#include <stdio.h>
#include <deque>
#include <stack>
#include <string>
using namespace std;
int N,result=0;
bool possible = true;
deque < int > dq;

void solution() {
    stack <int> s;
    int temp = 1;
    int dqsize = dq.size();
    for(int i=0; i<dqsize; i++) {
        int next = dq[i];
        // '('
        if(next == 0) {
            s.push(next);
            temp *= 2;
        }
        // '['
        else if(next == 2) {
            s.push(next);
            temp *= 3;
        }
        // ')'
        else if(next == 1) {
            if(s.empty()) {
                possible = false;
                break;
            }
            else if(s.top() == 0) {
                s.pop();
                if(dq[i-1] == 0) result += temp;
                temp = temp / 2;
            }
            else {
                possible = false;
                break;
            }
        }
        // ']'
        else if(next == 3) {
            if(s.empty()) {
                possible = false;
                break;
            }
            else if(s.top() == 2) {
                s.pop();
                if(dq[i-1] == 2) result += temp;
                temp = temp / 3;
            }
            else {
                possible = false;
                break;
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
    int sl = s.length();
    for(int i=0; i<sl; i++) {
        switch(s.at(i)) {
        case '(':
            dq.push_back(0);
            break;
        case ')':
            dq.push_back(1);
            break;
        case '[':
            dq.push_back(2);
            break;
        case ']':
            dq.push_back(3);
            break;
        }
    }
    solution();
    if(possible) printf("%d",result);
    else printf("0");
}
