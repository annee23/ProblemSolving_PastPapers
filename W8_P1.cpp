#include<iostream>
#include<vector>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T, N, M, a, b,t;
	cin >> T;
	while (T--) {
		cin >> M >> N;
		vector<int> score;
		for (int i = 0; i < M; i++) {
			cin >> t;
			score.push_back(t);
		}
		vector<int> slot;
		slot.resize(M+1);
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			slot[b] = a;
		}
		int sum = 0;
		bool flag = false;
		int count = 0;
		for (int i = 1; i < M; i++)
		{
			if (slot[i] < slot[i + 1]) {
				count++;
			}
			else {
				if (i == M - 1)
					flag = true;
				sum += score[count];
				count = 0;
			}
		}
		
			sum += score[count];
		

		cout << sum << "\n";
	}
	
}