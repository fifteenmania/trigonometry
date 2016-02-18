// trigonometry.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <ctime>
using namespace std;

string cosplb[] = { "cos0", "cos30", "cos60" };
string cosans[] = { "1", "√3/2", "1/2" };
string sinplb[] = { "sin0", "sin30", "sin60" };
string sinans[] = { "0", "1/2", "√3/2" };
string tanplb[] = { "tan0", "tan30", "tan60" };
string tanans[] = { "0", "1/√3", "√3" };

struct Problem {
	string problem;
	string ans;
};

Problem pbGenerate()
{
	Problem problem;
	int kind = rand() % 3;
	int num = rand() % 3;
	if (kind == 0) {
		problem.problem = cosplb[num];
		problem.ans = cosans[num];
	}
	else if (kind == 1) {
		problem.problem = sinplb[num];
		problem.ans = sinans[num];
	}
	else {
		problem.problem = tanplb[num];
		problem.ans = tanans[num];
	}
	
	return problem;
}

int main()
{
	ofstream test("test.txt");
	ofstream ans("ans.txt");
	int i, j = 0;
	Problem problem;

	for (i = 0; i < 40; i++) {
		for (j = 0; j < 5; j++) {
			problem = pbGenerate();

			test.width(3);
			test << i * 5 + j + 1;
			test << ". ";
			test.width(5);
			test << problem.problem;
			test << " =  " << "\t";

			ans.width(4);
			ans << i * 5 + j + 1;
			ans << ". ";
			ans.width(6);
			ans << problem.ans;
		}
		test << endl << endl << endl;
		ans << endl << endl;
	}

	test.close();
	ans.close();

	return 0;
}
