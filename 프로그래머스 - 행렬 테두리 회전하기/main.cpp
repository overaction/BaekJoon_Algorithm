#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
	int matrix[101][101];
	int num = 1;
	for(int i=0; i<rows; i++) {
		for(int j=0; j<columns; j++) {
			matrix[i][j] = num++;
		}
	}
	for(int i=0; i<queries.size(); i++) {
		int y1 = queries[i][0]-1;
		int x1 = queries[i][1]-1;
		int y2 = queries[i][2]-1;
		int x2 = queries[i][3]-1;

		int temp = matrix[y1][x1];
		int minimum = temp;
		// 왼쪽
		for(int j=y1; j<=y2-1; j++) {
			minimum = (minimum > matrix[j][x1]) ? matrix[j][x1] : minimum;
			matrix[j][x1] = matrix[j+1][x1];
			
		}
		// 아래
		for(int j=x1; j<=x2-1; j++) {
			minimum = (minimum > matrix[y2][j]) ? matrix[y2][j] : minimum;
			matrix[y2][j] = matrix[y2][j+1];
		}
		// 오른쪽
		for(int j=y2; j>=y1+1; j--) {
			minimum = (minimum > matrix[j][x2]) ? matrix[j][x2] : minimum;
			matrix[j][x2] = matrix[j-1][x2];
		}
		// 위
		for(int j=x2; j>=x1+1; j--) {
			minimum = (minimum > matrix[y1][j]) ? matrix[y1][j] : minimum;
			matrix[y1][j] = matrix[y1][j-1];
		}
		// 유실된 부분 채워넣기
		matrix[y1][x1+1] = temp;
		answer.push_back(minimum);
	}
    return answer;
}