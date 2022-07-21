#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 상 하 좌 우
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
bool visited[500][500][4];
int N,M;
vector <string> arr;
vector<int> answer;

int transform(char c, int dir) {
	if(c == 'L') {
		if(dir == 0) return 2;
		if(dir == 1) return 3;
		if(dir == 2) return 1;
		if(dir == 3) return 0;
	}
	else if(c == 'R') {
		if(dir == 0) return 3;
		if(dir == 1) return 2;
		if(dir == 2) return 0;
		if(dir == 3) return 1;
	}
}

void dfs(int y, int x, int dir, int cnt) {
	if(visited[y][x][dir] == true) {
		if(cnt != 0) answer.push_back(cnt);
		return;
	}
	visited[y][x][dir] = true;
	int ny,nx;
	int nD;

	if(arr[y][x] != 'S') nD = transform(arr[y][x],dir);
	ny = y + dy[nD];
	nx = x + dx[nD];

	if(ny >= N) ny = 0;
	if(nx >= M) nx = 0;
	if(ny < 0) ny = N-1;
	if(nx < 0) nx = M-1;

	return dfs(ny,nx,nD,cnt+1);
}

vector<int> solution(vector<string> grid) {
    N = grid.size();
	M = grid[0].size();
	arr = grid;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			for(int k=0; k<4; k++) {
				dfs(i,j,k,0);
			}
		}
	}
	sort(answer.begin(),answer.end());
    return answer;
}