#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <string>
using namespace std;

vector < char > v;
vector < char > calcV;
int solution() {
    int result = 0;
    int temp = 1;
    int vSize = v.size();
    for(int i=0; i<vSize; i++) {
        char now = v[i];
        if(now == '(') {
            calcV.push_back('(');
            temp *= 2;
        }
        else if(now == '[') {
            calcV.push_back('[');
            temp *= 3;
        }
        else if(now == ')') {
            if(calcV.empty() || calcV.back() != '(') return 0;
            if(v[i-1] == '(') {
                result += temp;
            }
            calcV.pop_back();
            temp /= 2;
        }
        else if(now == ']') {
            if(calcV.empty() || calcV.back() != '[') return 0;
            if(v[i-1] == '[') {
                result += temp;
            }
            calcV.pop_back();
            temp /= 3;
        }
    }
    if(!calcV.empty()) return 0; 
    return result;
}

int main() {
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        v.push_back(s[i]);
    }
    printf("%d\n",solution());
}
