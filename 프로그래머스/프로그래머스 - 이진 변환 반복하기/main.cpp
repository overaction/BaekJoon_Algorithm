#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zeros = 0;
    int cnt = 0;
    string temp;
    while(1) {
        if(s == "1") break;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '0') zeros++;
            else temp += s[i];
        }
        // 2진법으로 변환
        int nowSize = temp.size();
        temp = "";
        while(nowSize != 0) {
            temp += (nowSize % 2) + 48;
            nowSize /= 2;
        }
        reverse(temp.begin(), temp.end());
        cout << temp << endl;
        s = temp;
        temp = "";
        cnt++;
    }
    printf("%d %d\n",zeros,cnt);
    return answer;
}

int main() {
    solution("011000");
}