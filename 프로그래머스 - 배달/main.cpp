#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector < pair <int,int > > connect[51];
vector < int > dist;

void dks() {
	// <이동거리, 위치>
	priority_queue < pair < int,int >, vector < pair <int,int > >, greater < pair <int, int > > > pq;
	pq.push({0,1});
	
	while(!pq.empty()) {
		int nowDist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for(int i=0; i<connect[now].size(); i++) {
			int next = connect[now][i].first;
			int nextDist = connect[now][i].second;

			if(dist[next] > dist[now] + nextDist) {
				dist[next] = dist[now] + nextDist;
				pq.push({dist[next],next});
			}
		}
	}
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
	dist.resize(N+1,2e9);
	for(int i=0; i<road.size(); i++) {
		int a = road[i][0];
		int b = road[i][1];
		int distance = road[i][2];
		connect[a].push_back({b,distance});
		connect[b].push_back({a,distance});
	}
	// 1번마을 거리 0으로 시작
	dist[1] = 0;
	// 다익스트라
	dks();

	// 거리가 K 이하인 경우 답
	for(int i=1; i<=N; i++) {
		if(dist[i] <= K) answer++;
	}
    return answer;
}