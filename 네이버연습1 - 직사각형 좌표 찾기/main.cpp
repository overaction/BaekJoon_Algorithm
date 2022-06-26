#include <iostream>
using namespace std;
#include <vector>

vector < int > solution(vector <vector < int > > v) {
	vector < int > ans;
	int y,x;
	y = v[0][0]^v[1][0]^v[2][0];
	x = v[0][1]^v[1][1]^v[2][1];
	ans.push_back(y);
	ans.push_back(x);
	return ans;
}