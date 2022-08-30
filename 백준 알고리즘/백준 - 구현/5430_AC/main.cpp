#include <iostream>
#include <stdio.h>
#include <deque>
#include <string>
#include <vector>
using namespace std;
int T,n,cnt=0,result=0;
bool wrong = false;
string p;
deque < int > func;
deque < int > val;

void solution() {
    for(int i=0; i<func.size(); i++) {
        if(func[i] == 0) {
            deque < int > temp;
            int vsize = val.size();
            if(vsize > 0) {
                for(int i=0; i<vsize; i++) {
                    int next = val.front();
                    val.pop_front();
                    temp.push_front(next);
                }
                for(int i=0; i<vsize; i++) {
                    val.push_back(temp[i]);
                }
            }
        }
        else {
            if(val.size() > 0)
                val.pop_front();
            else {
                wrong = true;
                break;
            }
        }
    }
    if(wrong) printf("error\n");
    else {
        printf("[");
        for(int i=0; i<val.size()-1; i++) {
            printf("%d,",val[i]);
        }
        printf("%d]",val[val.size()-1]);
        printf("\n");
    }
}

int main()
{
    scanf("%d",&T);
    for(int t=1; t<=T; t++) {
        cin >> p;
        for(int i=0; i<p.length(); i++) {
            if(p.at(i) == 'R') func.push_back(0);
            else func.push_back(1);
        }
        scanf("%d",&n);
        cin >> p;
        for(int i=0; i<p.length(); i++) {
            if(isdigit(p.at(i))) {
               cnt++;
            }
            else {
                if(cnt == 1) {
                    val.push_back(p.at(i-1) - 48);
                }
                else if(cnt == 2) {
                    val.push_back((p.at(i-2)-48)*10 + p.at(i-1) - 48);
                }
                cnt = 0;
            }
        }
        solution();
        val.clear();
        func.clear();
        wrong = false;
    }
}
