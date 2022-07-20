#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
	int answer = 0;
    string convert;
	// 10진법 -> 3진법
	while(n != 0) {
		int num = n % 3;
		convert += num + '0';
		n /= 3;
	}
	// 3진법 -> 10진법
	int num = 1;
	for(int i=convert.size()-1; i>=0; i--) {
		answer += (convert[i] - '0') * num;
		num *= 3;
	}
	return answer;
}

int main() {
	cout << solution(125);
}