#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown+yellow;
    // 높이는 최소 3 이상
    int height = 3;
    int width = 0;
    while(1) {
        // 가로길이 구하기
        if(sum % height == 0) {
            width = sum / height;
            if((width-2)*(height-2) == yellow) {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
        height++; 
    }
    return answer;
}