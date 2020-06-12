#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T, N, W, V, K;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<int> Wt;
		vector<int> Ve;
		for (int i = 0; i < N; i++) {
			cin >> W;
			Wt.push_back(W);
		}
		for (int i = 0; i < N; i++) {
			cin >> V;
			for(int j=0;j<Wt[i];j++)
				Ve.push_back(V/Wt[i]);
		}
		sort(Ve.begin(), Ve.end(),greater<int>());
		int sum = 0;

		for (int i = 0; i < K; i++)
		{
			sum += Ve[i];
		}
		cout << sum << "\n";
	}
}