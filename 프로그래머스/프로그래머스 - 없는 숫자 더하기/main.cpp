#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <regex>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 55;
    for(int i=0; i<numbers.size(); i++) {
        answer -= numbers[i];
    }
    return answer;
}

int main() {
    
}