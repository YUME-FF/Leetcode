#pragma once
#include <string>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	int romanToInt(string s);
	bool isPalindrome(ListNode* head);
	bool canConstruct(string ransomNote, string magazine);
	vector<string> fizzBuzz(int n);
	ListNode* middleNode(ListNode* head);
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k);
	int numberOfSteps(int num);
	int maximumWealth(vector<vector<int>>& accounts);
};

