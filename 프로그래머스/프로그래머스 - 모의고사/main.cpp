#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> res;
	vector<int> cnt;
	int option[3][10] = {
		{1,2,3,4,5},
		{2,1,2,3,2,4,2,5},
		{3,3,1,1,2,2,4,4,5,5}
	};

	int op1=5, op2=8, op3=10; 
	int c1=0,c2=0,c3=0;
	for(int i=0; i<answers.size(); i++) {
		if(option[0][i%op1] == answers[i]) c1++;
	}
	for(int i=0; i<answers.size(); i++) {
		if(option[1][i%op2] == answers[i]) c2++;
	}
	for(int i=0; i<answers.size(); i++) {
		if(option[2][i%op3] == answers[i]) c3++;
	}
	int maximum = 0;
	maximum = (c1 > maximum) ? c1 : maximum;
	maximum = (c2 > maximum) ? c2 : maximum;
	maximum = (c3 > maximum) ? c3 : maximum;

	if(maximum == c1) res.push_back(1);
	if(maximum == c2) res.push_back(2);
	if(maximum == c3) res.push_back(3);

    return res;
}

int main() {
	vector<int> ans{1,2,3};
	printf("%d\n",ans[0]);
}