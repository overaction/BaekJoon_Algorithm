#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;

vector < string > v;

int main() {
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        string temp;
        for(int j=i; j<s.size(); j++) {
            temp += s[j];
        }
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
        cout << v[i] << endl;
}