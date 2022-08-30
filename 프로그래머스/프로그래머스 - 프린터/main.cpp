#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	queue < pair <int,int > > q;
	priority_queue <int> pq;
	for(int i=0; i<priorities.size(); i++) {
		q.push({i,priorities[i]});
		pq.push(priorities[i]);
	}

	int cnt = 0;
	while(1) {
		int idx = q.front().first;
		int pri = q.front().second;
		q.pop();
		// 우선순위가 더 높으면 프린트 
		if(pri >= pq.top()) {
			pq.pop();
			cnt++;
			if(idx == location) return cnt;
		}
		else {
			q.push({idx,pri});
		}
	}
}