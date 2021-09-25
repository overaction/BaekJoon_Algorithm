#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int T;

int main()
{
    cin >> T;
    string s;
    cin.ignore();
    for(int i=0; i<T; i++) {
        getline(cin,s);
        string temp;
        for(int j=0; j<s.size(); j++) {
            if(s[j] == ' ') {
                reverse(temp.begin(),temp.end());
                cout << temp << " ";
                temp.clear();
            }
            else temp += s[j];
        }
        reverse(temp.begin(),temp.end());
        cout << temp << endl;
    }
}
