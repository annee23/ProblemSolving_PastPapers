#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		int count = 1;
		int V[10001] = { 0, };
		int N; cin >> N;
		for (int i = 1; i <= N; i++) {
			int num;
			cin >> num;
			V[num] = i;
		}
		int before = V[N];
		for (int i = N; i >= 1; i--) {
			if (before > V[i])
				count++;
			before = V[i];
		}
		cout << count << "\n";
	}
}