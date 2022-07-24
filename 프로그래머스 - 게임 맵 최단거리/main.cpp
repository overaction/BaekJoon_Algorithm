#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int visited[100][100];
typedef struct op {
    int y,x;
}op;

void bfs(vector<vector<int> > maps) {
    queue <op> q;
    q.push({0,0});
    int cnt = 0;
    
    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        if(y == maps.size()-1 && x == maps[0].size()-1) {
            return;
        }
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= maps.size() || ny < 0 || nx >= maps[0].size() || nx < 0) continue;
            if(maps[ny][nx] == 0 || visited[ny][nx] != 1) continue;
            q.push({ny,nx});
            visited[ny][nx] += visited[y][x];
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    for(int i=0; i<maps.size(); i++)
        for(int j=0; j<maps[0].size(); j++)
            visited[i][j] = 1;
    bfs(maps);
    answer = visited[maps.size()-1][maps[0].size()-1] == 1 ? -1 : visited[maps.size()-1][maps[0].size()-1];
    return answer;
}