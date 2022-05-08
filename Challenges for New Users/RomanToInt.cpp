#include "RomanToInt.h"

int romanToInt(string s) {
	string dir, str;
	dir = s;
	int i = 0, n = 0, ans = 0;
	char symbol[7] = { 'M','D', 'C', 'L', 'X', 'V', 'I' };
	int value[7] = { 1000, 500, 100, 50, 10, 5, 1 };
	int pos_1 = dir.find("\"");
	int pos_2 = dir.find_last_of("\"");
	str = dir.substr(pos_1 + 1, pos_2 - pos_1 - 1);
	bool a = 1;
	/*
	cal the ans
	*/
	while (a) {
		int k = 0;
		i = 0;
		while (str[i] != '\0') {
			if (str[i] == symbol[n]) {
				k++;
			}
			if (k >= 2) {

			}
			i++;
		}
		ans += k * value[n];
		n += 1;
		if (n == 7)
			a = 0;
	}
	return ans;
}