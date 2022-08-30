#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void solution(string s, int b) {
	int cnt = 0;
	char now;
	int answer = 0;
	for(int i=s.size()-1; i>=0; i--) {
		now = s[i];
		if(now >= '0' && now <= '9') {
			answer += (now - '0') * (int)pow(b,cnt);
		}
		else {
			answer += (now - 'A' + 10) * (int)pow(b,cnt);
		}
		cnt++;
	}
	printf("%d\n",answer);
}

int main() {
	string N;
	int B;

	cin >> N >> B;
	solution(N,B);
}