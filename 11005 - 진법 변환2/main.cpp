#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

void solution(int n, int b) {
	vector < int > result;
	while(n != 0) {
		result.push_back(n%b);
		n = n / b;
	}
	for(int i=result.size()-1; i>=0; i--) {
		if(result[i] >= 0 && result[i] <= 9) cout << (char)(result[i] + '0');
		else cout << (char)(result[i] + 'A' - 10);
	}
}

int main() {
	int N,B;
	scanf("%d %d",&N,&B);
	solution(N,B);
}