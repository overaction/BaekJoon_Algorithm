#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <regex>
using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
bool visited[100][100];

int bfs(int y, int x, int m, int n, vector<vector<int>> picture) {
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = 1;
    int nowColor = picture[y][x];
    int size = 1;
    while(!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int newy = ny + dy[i];
            int newx = nx + dx[i];
            if(newy < 0 || newy >= m || newx < 0 || newx >= n) continue;
            if(visited[newy][newx] || picture[newy][newx] != nowColor) continue;

            visited[newy][newx] = true;
            q.push({newy,newx});
            size++;
        }
    }
    return size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) visited[i][j] = false;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(picture[i][j] != 0 && !visited[i][j]) {
                int nowSize = bfs(i,j,m,n,picture);
                if(nowSize > max_size_of_one_area) max_size_of_one_area = nowSize;
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    
}