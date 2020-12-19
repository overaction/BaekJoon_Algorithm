#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct str{
    int cctv; //cctv 종류
    int y; //cctv y좌표
    int x; //cctv x좌표
    str(int cctv,int y,int x):cctv(cctv),y(y),x(x){};
};

int N,M;
int ans=100; //사각 지대 최소값
int cctv_cnt=0; //cctv 개수
vector<vector<int>> map(8,vector<int>(8,0)); //사무실
vector<str> vec;

void move(int dir,int y,int x){

    switch(dir){

        //북
        case 0:
            for(int i=y-1;i>=0;i--){
                if(map[i][x]==6) break;
                if(map[i][x]==0) map[i][x]=-1; //cctv 감시 완료
            }
            break;

        //동
        case 1:
            for(int j=x+1;j<M;j++){
                if(map[y][j]==6) break;
                if(map[y][j]==0) map[y][j]=-1;
            }
            break;

        //남
        case 2:
            if(dir==2){
                for(int i=y+1;i<N;i++){
                    if(map[i][x]==6) break;
                    if(map[i][x]==0) map[i][x]=-1;
                }
            }
            break;

        //서
        case 3:
            for(int j=x-1;j>=0;j--){
                if(map[y][j]==6) break;
                if(map[y][j]==0) map[y][j]=-1;
            }

    }

}

void dfs(int step){

    if(step==cctv_cnt){

        int cnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]==0)
                    cnt++;
            }
        }

        ans=min(ans,cnt);
        return;
    }

    int cctv=vec[step].cctv;
    int y=vec[step].y;
    int x=vec[step].x;

    //이전에 확인한 사무실 상태값 저장
    vector<vector<int>> map2=map;

    switch(cctv){

        case 1:
            //북,동,남,서
            for(int dir=0;dir<4;dir++){
                move(dir,y,x);
                dfs(step+1);

                map=map2;
            }
            break;

        case 2:
            //북남,동서
            for(int dir=0;dir<2;dir++){
                move(dir,y,x);
                move(dir+2,y,x);
                dfs(step+1);

                map=map2;
            }
            break;

        case 3:
            //북동,동남,남서,서북
            for(int dir=0;dir<4;dir++){
                move(dir,y,x);
                move((dir+1)%4,y,x);
                dfs(step+1);

                map=map2;
            }
            break;

        case 4:
            //북동남,동남서,남서북,서북동
            for(int dir=0;dir<4;dir++){
                move(dir,y,x);
                move((dir+1)%4,y,x);
                move((dir+2)%4,y,x);
                dfs(step+1);

                map=map2;
            }
            break;

        case 5:
            for(int dir=0;dir<4;dir++)
                move(dir,y,x);

            dfs(step+1);
    }

}


int main(){

    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]!=0 && map[i][j]!=6){
                cctv_cnt++;
                vec.push_back(str(map[i][j],i,j));
            }
        }
    }

    dfs(0);
    cout<<ans<<endl;

    return 0;
}
