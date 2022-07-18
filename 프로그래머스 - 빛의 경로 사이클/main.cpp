#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int row,col;
vector<int> v;
bool check[500][500][4];
char arr[500][500];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

void dfs(int y, int x, int dir, int len){
    if(check[y][x][dir]){
        v.push_back(len-1);
        return;
    }
    check[y][x][dir]=true;
    char c = arr[y][x];
    int ny,nx,nd=dir;
    if(c=='L')  nd = (dir+3)%4;
    else if(c=='R') nd = (dir+1)%4;
    ny = y+dy[nd];
    nx = x+dx[nd];
    if(ny<0) ny+=row;
    else if(ny>=row) ny-=row;
    if(nx<0) nx+=col;
    else if(nx>=col) nx-=col;
	
    dfs(ny,nx,nd,len+1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    row = grid.size();
    col = grid[0].size();
    
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            arr[i][j]=grid[i][j];
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            for(int k=0;k<4;k++){
                if(check[i][j][k]) continue;
                dfs(i,j,k,1);
            }
        }
    }
    sort(v.begin(),v.end());
    answer = v;
    return answer;
}