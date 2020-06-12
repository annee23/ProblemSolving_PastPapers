#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<cmath>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int j = s.size() - 1;
		bool flag = false;
		for (int i = 0; i < s.size(); i++,j--) {
			if (i == j)
				break;
			if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122)
			{
				if (s[j] >= 65 && s[j] <= 90 || s[j] >= 97 && s[j] <= 122) {
					if (s[i] == s[j] || s[i] - 32 == s[j] || s[i] == s[j] - 32)
						continue;
					else
					{
						cout << "No\n";
						flag = true;
						break;
					}
				}
				else{
					while (!(s[j] >= 65 && s[j] <= 90 || s[j] >= 97 && s[j] <= 122))
						j--;
					if (i == j)
						break;
					if (s[i] == s[j] || s[i] - 32 == s[j] || s[i] == s[j] - 32)
						continue;
					else
					{
						cout << "No\n";
						flag = true;

						break;
					}
				}

			}
			else 
			{
				while (!(s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122))
					i++;
				if (i == j)
					break;
				if (s[j] >= 65 && s[j] <= 90 || s[j] >= 97 && s[j] <= 122) {
					if (s[i] == s[j] || s[i] - 32 == s[j] || s[i] == s[j] - 32)
						continue;
					else
					{
						cout << "No\n";
						flag = true;

						break;
					}
				}
				else {
					while (!(s[j] >= 65 && s[j] <= 90 || s[j] >= 97 && s[j] <= 122))
						j--;
					if (i == j)
						break;
					if (s[i] == s[j] || s[i] - 32 == s[j] || s[i] == s[j] - 32)
						continue;
					else
					{
						cout << "No\n";
						flag = true;

						break;
					}
				}

			}

		}
		if (!flag)
			cout << "Yes\n";
	}
	return 0;
}
