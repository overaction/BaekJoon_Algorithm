#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool calculate(int num) {
	int sum = 0;
	for(int i=1; i*i <= num; i++) {
		if(num % i == 0) sum ++;
	}
	printf("%d\n",sum);
	return true;
}

int solution(int left, int right) {
    int answer = 0;
	for(int i=left; i<=right; i++) {
		if(calculate(i) == true) answer += i;
		else answer -= i;
	}
	printf("%d\n",answer);
    return answer;
}