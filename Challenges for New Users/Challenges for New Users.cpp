// Challenges for New Users.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Solution.h"
using namespace std;

int main()
{
	Solution so;
	string input1, input2;
	vector<vector<int>> mat =
	//{ {1, 1, 0, 0, 0},
	//{1, 1, 1, 1, 0},
	//{1, 1,0,1, 0},
	//{1, 1,0,1, 0} ,
	//{1, 1,0,1, 0}};

	//{{1, 1, 1, 1, 1, 0},
	//{1, 1, 1, 1, 1, 0},
	//{1, 1, 1, 1, 1, 0} };

	{ {1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0}};

	so.kWeakestRows(mat, 1);

	//while (1) {
	//	getline(cin, input1);
	//	getline(cin, input2);
	//	bool tf = so.canConstruct(input1, input2);
	//	cout << tf << endl;
	//	//int ans = so.romanToInt(input);
	//	//cout << ans << endl;
	//}
}