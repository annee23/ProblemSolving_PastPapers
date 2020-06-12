#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<cmath>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
int SubString(string s, string r) {
	int Win_cntArr[200] = { 0, }, R_cntArr[200] = { 0, };
	int start = 0, end = 0, winlenth = 0, cnt = 0;
	int s_len = s.length(), r_len = r.length();
	int minlen = s_len + 1;
	for (int i = 0; i < r.size(); i++) {
		R_cntArr[r[i]]++;
	}
	while (end <= s_len) {
		Win_cntArr[s[end]] ++;
		if (R_cntArr[s[end]] >= Win_cntArr[s[end]])
			cnt++;
		while(cnt==r_len){
			winlenth = end - start + 1;
			if (winlenth < minlen)
				minlen = winlenth;
			if (R_cntArr[s[start]] >= Win_cntArr[s[start]])
				cnt--;
			Win_cntArr[s[start]]--;
			start++;

		}
		end++;
	}
	if (minlen > s_len)
		return 0;
	return minlen;
}
int main() {
	std::ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		string s, r;
		cin >> s >> r;
		cout << SubString(s, r) << "\n";
	}
	return 0;
}
