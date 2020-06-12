#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<deque>
#include<cmath>
//win=1,continue=2
using namespace std;
int check(int x, int y, int color,int om_table[17][17]) {
	int tmp_x = x, tmp_y = y, cnt = 0, current = color;
	while (current == color) {
		cnt++;
		current = om_table[--tmp_x][tmp_y];
	}
	tmp_x = x, tmp_y = y, current = color;
	while (current == color) {
		cnt++;
		current = om_table[++tmp_x][tmp_y];
	}
	if ((cnt - 1 )== 5)
		return 1;
	///////////////////////////////////////////////
	tmp_x = x, tmp_y = y, current = color, cnt = 0;
	while (current == color) {
		cnt++;
		current = om_table[tmp_x][--tmp_y];
	}
	tmp_x = x, tmp_y = y, current = color;
	while (current == color) {
		cnt++;
		current = om_table[tmp_x][++tmp_y];
	}
	if ((cnt - 1) == 5)
		return 1;
	///////////////////////////////////////////////
	tmp_x = x, tmp_y = y, current = color, cnt = 0;
	while (current == color) {
		cnt++;
		current = om_table[--tmp_x][++tmp_y];
	}
	tmp_x = x, tmp_y = y, current = color;
	while (current == color) {
		cnt++;
		current = om_table[++tmp_x][--tmp_y];
	}
	if ((cnt - 1 )== 5)
		return 1;
	///////////////////////////////////////////////
	tmp_x = x, tmp_y = y, current = color, cnt = 0;
	while (current == color) {
		cnt++;
		current = om_table[--tmp_x][--tmp_y];
	}
	tmp_x = x, tmp_y = y, current = color;
	while (current == color) {
		cnt++;
		current = om_table[++tmp_x][++tmp_y];
	}
	if ((cnt - 1) == 5)
		return 1;
	return 2;

}
int main() {
	std::ios::sync_with_stdio(false);
	int T, x = 0, y = 0;
	cin >> T;
	while (T--) {
		//int arr[17][17] = { -1, };
		int om_table[17][17] = { 0, };
		int result = 2;
		int color = 0;
		int end = 0, winner = 0;
		for (int i = 0; i < 225; i++) {
			if (result != 2)
				cin >> x >> y;
			else
			{
				if (i % 2 == 0)
					color = 1;
				else
					color = 2;
				cin >> x >> y;
				om_table[x][y] = color;
				result = check(x, y, color,om_table);
				if (result == 1)
				{
					 winner = color;
					 end = i;
				}
			}
		}
		if(winner==1)
			cout << end + 1 << " B\n";
		else
			cout << end + 1 << " W\n";
	}
}
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<vector>
//#include<cmath>
//#include<deque>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	int T; cin >> T;
//	int N, M, x, y;
//	char a;
//	while (T--) {
//		cin >> N >> M;
//		vector<pair<int, int>> v[26];
//		for (int i = 0; i < M; i++) {
//			cin >> a >> x >> y;
//			pair<int, int> p;
//			p.first = x;
//			p.second = y;
//			v[a -65].push_back(p);
//		}
//
//		for (int i = 0; i < 26; i++) {
//			while (v[i].size() != 0) {
//				vector<int> tmp;
//				do {
//					tmp.push_back(pow(v[i][0].first - v[i][1].first, 2) + pow(v[i][0].second - v[i][1].second, 2));
//
//				} while (next_permutation(v[i].begin(), v[i].end()));
//				sort(tmp.begin(), tmp.end());
//				int min = tmp[0];
//				sort(v[i].begin(), v[i].end());
//				vector<pair<pair<int, int>,pair<int,int>>> compare;
//				
//				do {
//					
//				 if (min == pow(v[i][0].first - v[i][1].first, 2) + pow(v[i][0].second - v[i][1].second, 2))
//					{
//						pair< pair<int, int>, pair<int, int >> p;
//						p.first = v[i][0];
//						p.second = v[i][1];
//						compare.push_back(p);
//						/*cout << (char)(i+65) << " " << v[i][0].first << " " << v[i][0].second << " " << v[i][1].first << " " << v[i][1].second << "\n";
//						v[i].pop_front();
//						v[i].pop_front();*/
//					}
//
//				} while (next_permutation(v[i].begin(), v[i].end()));
//				min = 100;
//				int tmp_j = 0;
//				for (int j = 0; j < compare.size(); j++) {
//					if (min > compare[j].first.second + compare[j].second.second)
//					{
//						tmp_j = j;
//						min = compare[j].first.second + compare[j].second.second;
//					}
//					else if (min == compare[j].first.second + compare[j].second.second)
//					{
//						if (compare[j].first.first + compare[j].second.first > compare[tmp_j].first.first + compare[tmp_j].second.first)
//							continue;
//						else
//							tmp_j = j;
//					}
//				}
//				cout << (char)(i + 65) << " " << compare[tmp_j].second.first << " " << compare[tmp_j].second.second <<" "<< compare[tmp_j].first.first << " " << compare[tmp_j].first.second << "\n";
//				for (int j = 0; j < v[i].size(); j++)
//				{
//					if (v[i][j] == compare[tmp_j].first || v[i][j] == compare[tmp_j].second)
//					{
//						v[i].erase(v[i].begin() + j);
//						v[i].erase(v[i].begin() + j);
//					}
//				}
//			}
//		}
//
//	}
//	return 0;
//}
