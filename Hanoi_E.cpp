#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T, N, t;
	cin >> T;
	while (T--) {
		cin >> N;
		queue<int>q;
		int count = 0;
		int start = -1;
		q.push(start);
		for (int i = 0; i < N; i++) {
			cin >> t;
			q.push(t);
		}
		for (int i = N; i > 0;) {
			if (i == start)
			{
				t = q.front();
				q.pop();
				q.push(t);
			}
			if (q.front() == start)
				count++;
			if (q.front() == i)
			{
				i--;
				q.pop();
			}
			else {
				t = q.front();
				q.pop();
				q.push(t);
			}
		}
		cout << count << "\n";

	}
	return 0;
}