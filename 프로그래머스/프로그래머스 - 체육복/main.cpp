#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
	vector<int> check(n,1);
	for(int i=0; i<lost.size(); i++) check[lost[i]-1]--;
	for(int i=0; i<reserve.size(); i++) check[reserve[i]-1]++;

	for(int i=0; i<n; i++) {
		if(check[i] == 0 && i>0 && check[i-1] == 2) {
			check[i-1]--;
			check[i]++;
		}
		else if(check[i] == 0 && i<n-1 && check[i+1] == 2) {
			check[i+1]--;
			check[i]++;
		}
	}
	for(int i=0; i<n; i++) {
		if(check[i] != 0) answer++;
	}
    return answer;
}

int main() {
	printf("%d\n",abs(9-10));
	printf("%d\n",abs(10-11));
}