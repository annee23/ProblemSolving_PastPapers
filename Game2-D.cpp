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
		int n;
		cin >> n;
		vector<pair<int,int> >item;
		string s;
		int start, finish;
		for (int i = 0; i < n; i++) {
			cin >> s >> start >> finish;
			pair<int, int> p;
			p.first = finish;
			p.second = start;
			item.push_back(p);
		}
		sort(item.begin(), item.end());
		int count = 1, current = 0;
		for (int i = 1; i < n; i++) {
			if (item[i].second >= item[current].first)
			{
				current = i;
				count++;
			}
		}
		cout << count << "\n";
	}
	return 0;
}
