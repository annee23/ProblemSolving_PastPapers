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
		int N, K;
		cin >> N >> K;
		vector<int>Wei;
		vector<int> Val;
		vector<vector<int>>DP;
		DP.resize(N+1);
		for (int i = 0; i < N+1; i++)
			DP[i].resize(K+1);
		int t;
		for (int i = 0; i < N; i++)
		{
			cin >> t;  Wei.push_back(t);
		}
		for (int i = 0; i < N; i++)
		{
			cin >> t;  Val.push_back(t);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				if (j - Wei[i-1] >= 0)
					DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - Wei[i-1]] + Val[i-1]);
				else DP[i][j] = DP[i - 1][j];
			}
		}
		cout << DP[N][K] << "\n";
	}


	return 0;
}
