#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater <int>());
    int maxCnt = 0;
    int min = 0;
    for(int i=0; i<citations.size(); i++) {
        if(citations[i] >= (i+1)) {
            answer = i+1;
        }
    }
    return answer;
}

int main() {
    vector <int> c;
    c.push_back(6);
    c.push_back(5);
    printf("%d\n",solution(c));
}