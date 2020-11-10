#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int N, house = 0;
int maze[26][26];
int visited[26][26];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

deque < int > q;

void bfs(int y, int x) {
    deque < pair <int,int > > dq;
    int number = 1;
    visited[y][x] = 1;
    dq.push_back(make_pair(y,x));
    house++;
    maze[y][x] = house;
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int newy = y + dy[i];
            int newx = x + dx[i];
            if(newy > N || newy <= 0 || newx > N || newx <= 0)
                continue;
            if(maze[newy][newx] == 0) continue;
            if(visited[newy][newx] == 1) continue;
            visited[newy][newx] = 1;
            maze[newy][newx] = house;
            dq.push_back(make_pair(newy,newx));
            number++;
        }
    }
    q.push_back(number);
}

int main()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%1d",&maze[i][j]);
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(visited[i][j] || maze[i][j] == 0) continue;
            bfs(i,j);
        }
    }

    sort(q.begin(),q.end());

    printf("%d\n",house);

    for(int i=0; i<q.size(); i++) {
        int num = q[i];
        printf("%d\n",num);
    }
}
