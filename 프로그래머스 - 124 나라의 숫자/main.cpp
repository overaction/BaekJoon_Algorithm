#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


string solution(int n)
{
	string answer = "";
	while (n)
	{
		if (n % 3 == 0) {
			answer.insert(0, to_string(4));
			n -= 3;
		}
		else answer.insert(0, to_string(n % 3));
		n /= 3;
	}
	
	return answer;
}

int main() {
    cout << solution(21);
}