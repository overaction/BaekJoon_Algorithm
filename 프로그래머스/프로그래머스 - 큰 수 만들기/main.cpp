#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.size() - k;
    int start = 0;
    int maxIdx = -1;
    // (숫자 길이 - 제거할 숫자 개수) 만큼 선택한다
    for(int i=1; i<=n; i++) {
        char maximum = number[start];
        maxIdx = start;
        // maxIdx에 상관없이 고를때마다 k에서 1씩 증가
        for(int j=maxIdx+1; j<k+i; j++) {
            if(maximum < number[j]) {
                maximum = number[j];
                maxIdx = j;
            }
        }
        answer += maximum;
        start = maxIdx+1;
    }
    return answer;
}