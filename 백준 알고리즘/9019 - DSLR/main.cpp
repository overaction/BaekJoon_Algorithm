#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
int visited[10000];

int main() {
	int T;
	string A;
	int B;
	scanf("%d",&T);
	for(int i=0; i<T; i++) {
		cin >> A >> B;
		solution(A,B);
	}
}