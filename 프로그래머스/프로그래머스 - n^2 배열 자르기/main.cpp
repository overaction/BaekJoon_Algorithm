#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left; i<=right; i++) {
        int mod = i%n;
        int divide = i/n;

        // 나머지가 몫보다 크다면
        if(mod < divide) answer.push_back(divide+1);
        // 아니라면
        else answer.push_back(mod+1);
    }
    return answer;
}