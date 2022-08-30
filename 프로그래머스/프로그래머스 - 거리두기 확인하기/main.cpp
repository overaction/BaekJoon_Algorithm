#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

typedef struct op {
	int y,x;
	int dist;
}op;

int bfs(vector<string> places, int sy, int sx) {
	queue < op > q;
	vector< vector < bool > > visited(5,vector<bool>(5,false));
	visited[sy][sx] = true;
	q.push({sy,sx,0});

	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dist = q.front().dist;
		q.pop();
		for(int i=0; i<4; i++) {
			int ny = y+dy[i];
			int nx = x+dx[i];
			// 장소를 벗어날 경우
			if(ny >= 5 || ny < 0 || nx >= 5 || nx < 0) continue;
			// 이미 방문한 장소일 경우
			if(visited[ny][nx]) continue;
			// P 이면서 거리가 2 이하인 경우 return 1
			if(places[ny][nx] == 'P' && dist+1 <= 2) return 1;
			// 0 이면서 거리가 2 이하인 경우 push
			if(places[ny][nx] == 'O' && dist+1 <= 2) q.push({ny,nx,dist+1});
		}
	}
	// 거리두기를 잘 지키고있다면 0 반환
	return 0;
}

int searching(vector<string> places) {
	for(int i=0; i<places.size(); i++) {
		for(int j=0; j<places[i].size(); j++) {
			if(places[i][j] == 'P') {
				if(bfs(places,i,j) == 1) return 0;
			}
		} 
	}
	return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
	for(int i=0; i<places.size(); i++) {
		answer.push_back(searching(places[i]));
	}
    return answer;
}