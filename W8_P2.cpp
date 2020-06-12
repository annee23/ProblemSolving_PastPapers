#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<cmath>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
int max(int x, int y) {
	if (x > y)
		return x;
	else return y;
}
int main() {
	std::ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		vector<vector<int>>DP;
		string s1, s2;
		cin >> s1 >> s2;
		int N, M;
		N = s1.size();
		M = s2.size();
		DP.resize(N + 1);
		for (int i = 0; i < N+1; i++)
			DP[i].resize(M+1);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (s1[i-1] == s2[j-1])
					DP[i][j] = DP[i - 1][j - 1] + 1;
				else
					DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
		cout << DP[N][M] << "\n";

	}


	return 0;
}
