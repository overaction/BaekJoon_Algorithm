#include <string>
#include <vector>
#include <iostream>
using namespace std;

int calculate(int n) {
    int cnt = 0;
    while(n != 0) {
        if(n%2 == 1) cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int check = calculate(n);
    int answer = n+1;
    while(1) {
        if(check == calculate(answer)) return answer;
        answer++;
    }
}