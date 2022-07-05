#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <regex>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int i=0; i<absolutes.size(); i++) {
        if(signs[i] == false) answer -= absolutes[i];
        else answer += absolutes[i];
    }
    return answer;
}

int main() {
    
}