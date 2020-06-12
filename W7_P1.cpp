#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T, N, t;
	cin >> T;
	while (T--) {
		cin >> N;
		int count = 0;
		vector<int> v;
		vector<int> xpow;
		for (int i = 0; i < N; i++) {
			cin >> t;
			v.push_back(t);
		}
		int a, b, x;
		cin >> a >> b >> x;
		xpow.push_back(1);
		for (int i = 1; i < N; i++)
		{
			xpow.push_back((xpow[i - 1] * x) % 1013);
		}
		sort(v.begin(), v.end());
		do{
			int sum = 0;
			for (int j = 0; j < N; j++) {
				sum += (xpow[j] * v[j]) % 1013;
			}
			sum = sum%1013;
			if (sum <= b && sum >= a)
				count++;
		} while (next_permutation(v.begin(), v.end()));
		cout << count << "\n";
	}
}