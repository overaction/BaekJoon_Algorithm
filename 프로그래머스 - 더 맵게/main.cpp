#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
	priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
	while(pq.top() < K) {
		if(pq.size() == 1) {
			answer = -1;
			break;
		}
		int top = pq.top();
		pq.pop();
		int next = pq.top();
		pq.pop();
		int mixed = top + next*2;
		pq.push(mixed);
		answer++;
	}
    return answer;
}

int main() {
	 priority_queue<int, vector<int>, greater<int> > pq;
	 pq.push(1);
	 pq.push(2);
	 pq.push(3);
	 pq.pop();
	 pq.push(0);
	 printf("%d\n",pq.top());
}