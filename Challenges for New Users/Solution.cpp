#include "Solution.h"
/*
	num:13.Roman to Integer
	*input without ""
	ex:III,LVIII,MCM
*/
int Solution::romanToInt(string dir) {

	int i = 0, ans = 0;
	char symbol[7] = { 'M','D', 'C', 'L', 'X', 'V', 'I' };
	int value[7] = { 1000, 500, 100, 50, 10, 5, 1 };
	while (i < dir.length()) {
		int n = 0;
		while (n != 7) {
			if (dir[i] == symbol[n] || dir[i + 1] == symbol[n]) {
				if (dir[i + 1] == symbol[n] && dir[i] != symbol[n]) {
					ans += value[n];
					int n2 = n;
					while (dir[i] != symbol[n2]) {
						n2++;
					}
					ans -= value[n2];
					i++;
				}
				else {
					ans += value[n];
				}
				n = 6;
			}
			n++;
		}
		i++;
	}
	return ans;
}
/*
solution example;

private: unordered_map<char, int> alphabet;
public:
	int romanToInt(string s) {
		initAlphabet();
		int result = 0;
		for (int i = 0; i < s.length() - 1; i++) {
			if (alphabet[s[i]] < alphabet[s[i + 1]])
				result = result - alphabet[s[i]];
			else
				result = result + alphabet[s[i]];
		}
		return result + alphabet[s.back()];
	}

private:
	void initAlphabet() {
	alphabet = { {'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000} };
		};
*/

/*
	num:234. Palindrome Linked List
	*input: isPalindrome([1,2,2,1])

	slow-fast point
*/
bool Solution::isPalindrome(ListNode* head) {
	//cal the length of Linklist
	ListNode* p = head;
	int lenLL = 0;
	while (p) {
		lenLL++;
		p = p->next;
	}

	if (lenLL == 1) {
		return true;
	}
	//Using FastSlow point reverse the Linklist
	p = NULL;
	ListNode* q = NULL;
	ListNode* slowpoint = head;
	ListNode* fastpoint = head;

	while (fastpoint != NULL && fastpoint->next != NULL) {
		q = p;
		p = slowpoint;
		slowpoint = slowpoint->next;
		//after while, fast reach end while slow is half
		fastpoint = fastpoint->next->next;
		p->next = q;
	}
	if (lenLL%2 != 0) {
		slowpoint = slowpoint->next;
	}
	while (slowpoint && p) {
		if (slowpoint->val != p->val) {
			return false;
		}
		slowpoint = slowpoint->next;
		p = p->next;
	}
	return true;
}

/*
	num:383. Ransom Note
	*input:ransomNote = "a", magazine = "aab"
	*output:true
	Given two strings ransomNote and magazine, 
	return true if ransomNote can be constructed from magazine and false otherwise.
	Each letter in magazine can only be used once in ransomNote.
*/
bool Solution::canConstruct(string ransomNote, string magazine) {
	int ransomNotelist[26] = {0};
	int magazinelist[26] = { 0 };
	int i = 0;
	while (magazine.length() - i) {
		magazinelist[int(magazine[i]) - 97]++;
		i++;
	}
	i = 0;
	while (ransomNote.length() - i) {
		ransomNotelist[int(ransomNote[i]) - 97]++;
		i++;
	}
	i = 0;
	while (26 - i) {
		if (magazinelist[i] - ransomNotelist[i] >= 0) {
			i++;
		}
		else {
			return false;
		}
	}
	return true;
}

/*
	num:412 Fizz Buizz
	Given an integer n, return a string array answer (1-indexed) where:
	answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
	answer[i] == "Fizz" if i is divisible by 3.
	answer[i] == "Buzz" if i is divisible by 5.
	answer[i] == i (as a string) if none of the above conditions are true.
*/
vector<string> Solution::fizzBuzz(int n) {
	vector<string> intArr;
	int i = 1;
	while (n - i + 1) {
		if (i % 3 == 0 && i % 5 == 0) {
			intArr.push_back( "FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			intArr.push_back("Fizz");
		}
		else if (i % 5 == 0)
		{
			intArr.push_back("Buzz");
		}
		else {
			intArr.push_back(to_string(i));
		}
		i++;
	}
	return intArr;
}

/*
	num:876 Middle of the Linked list
	Given the head of a singly linked list, 
	return the middle node of the linked list.
	If there are two middle nodes, 
	return the second middle node.
*/
ListNode* Solution::middleNode(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

/*
	num:1337 The K Weakest Rows in a Matrix
	You are given an m x n binary matrix mat of 1's (representing soldiers) 
	and 0's (representing civilians). The soldiers are positioned in front of the civilians. 
	That is, all the 1's will appear to the left of all the 0's in each row.

	A row i is weaker than a row j if one of the following is true:
	The number of soldiers in row i is less than the number of soldiers in row j.
	Both rows have the same number of soldiers and i < j.
	Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
*/
vector<int> Solution::kWeakestRows(vector<vector<int>>& mat, int k) {
	vector<int> intArr;
	vector<int> intMap;
	int i = 0;
	while (mat.size() - i) {
		int j = 0, ans = 0;
		while (mat[0].size() - j) {
			if (mat[i][j] == 1) {
				ans++;
			}
			else if (mat[i][j] == 0) {
				j = mat[0].size() - 1;
			}
			j++;
		}
		intArr.push_back(ans);
		i++;
	}
	i = 0;
	while (k - i) {
		intMap.push_back(distance(intArr.begin(), min_element(intArr.begin(), intArr.end())));
		intArr[distance(intArr.begin(), min_element(intArr.begin(), intArr.end()))] = 101;
		i++;
	}
	
	return intMap;
}

/*
	num:1342 Number of Steps to Reduce a Number to Zero
	Given an integer num, 
	return the number of steps to reduce it to zero.

	In one step, if the current number is even, 
	you have to divide it by 2, otherwise,
	you have to subtract 1 from it.

*/
int Solution::numberOfSteps(int num) {
	int i = 0;
	if (num == 1 || num == 0) {
		return num;
	}
	while (num != 0) {
		while (num % 2 == 0) {
			num /= 2;
			i++;
		}
		while (num % 2 != 0) {
			num -= 1;
			i++;
		}
	}
	return i;
}

/*
	num:1342 Richest Customer Wealth
	You are given an m x n integer grid accounts
	where accounts[i][j] is the amount of money 
	the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. 
	Return the wealth that the richest customer has.

	A customer's wealth is the amount of money they have in all their bank accounts. 
	The richest customer is the customer that has the maximum wealth.
*/
int Solution::maximumWealth(vector<vector<int>>& accounts) {
	int  max = 0, i = 0;
	while (accounts.size() - i) {
		int sum = 0, j = 0;
		while (accounts[i].size() - j) {
			sum += accounts[i][j];
			j++;
		}
		if (max < sum) {
			max = sum;
		}
		i++;
	}
	return max;
}