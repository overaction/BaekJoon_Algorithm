#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cache[500][500];

int solution(vector<vector<int>> triangle) {
    cache[0][0] = triangle[0][0];
    cache[1][0] = triangle[0][0] + triangle[1][0];
    cache[1][1] = triangle[0][0] + triangle[1][1];

    int answer = 0;
    int height = triangle.size();
    for(int i=2; i<triangle.size(); i++) {
        for(int j=0; j<triangle[i].size(); j++) {
            if(j == 0) cache[i][j] = triangle[i][j] + cache[i-1][j]; 
            else if(j == triangle[i].size()-1) cache[i][j] = triangle[i][j] + cache[i-1][j-1];
            else cache[i][j] = max(triangle[i][j] + cache[i-1][j-1], triangle[i][j] + cache[i-1][j]);
        }
    }
    for(int i=0; i<height; i++) {
        answer = max(answer,cache[height-1][i]);
    }
    return answer;
}