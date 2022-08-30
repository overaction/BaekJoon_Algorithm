#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct str{
    int cctv; //cctv ����
    int y; //cctv y��ǥ
    int x; //cctv x��ǥ
    str(int cctv,int y,int x):cctv(cctv),y(y),x(x){};
};

int N,M;
int ans=100; //�簢 ���� �ּҰ�
int cctv_cnt=0; //cctv ����
vector<vector<int>> map(8,vector<int>(8,0)); //�繫��
vector<str> vec;

void move(int dir,int y,int x){
    switch(dir){
        //��
        case 0:
            for(int i=y-1;i>=0;i--){
                if(map[i][x]==6) break;
                if(map[i][x]==0) map[i][x]=-1; //cctv ���� �Ϸ�
            }
            break;
        //��
        case 1:
            for(int j=x+1;j<M;j++){
                if(map[y][j]==6) break;
                if(map[y][j]==0) map[y][j]=-1;
            }
            break;
        //��
        case 2:
            if(dir==2){
                for(int i=y+1;i<N;i++){
                    if(map[i][x]==6) break;
                    if(map[i][x]==0) map[i][x]=-1;
                }
            }
            break;
        //��
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

    //������ Ȯ���� �繫�� ���°� ����
    vector<vector<int>> map2=map;

    switch(cctv){
        case 1:
            //��,��,��,��
            for(int dir=0;dir<4;dir++){
                move(dir,y,x);
                dfs(step+1);
                map=map2;
            }
            break;

        case 2:
            //�ϳ�,����
            for(int dir=0;dir<2;dir++){
                move(dir,y,x);
                move(dir+2,y,x);
                dfs(step+1);
                map=map2;
            }
            break;

        case 3:
            //�ϵ�,����,����,����
            for(int dir=0;dir<4;dir++){
                move(dir,y,x);
                move((dir+1)%4,y,x);
                dfs(step+1);
                map=map2;
            }
            break;

        case 4:
            //�ϵ���,������,������,���ϵ�
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
