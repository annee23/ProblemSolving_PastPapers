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
		int L, sX, sY, fX, fY;
		cin >> L >> sX >> sY >> fX >> fY;
		int Dist[500][500];
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < L; j++) {
				Dist[i][j] = -1;
			}
		}
		//int dy[8], dx[8];
		int dy[8] = { -1,-2,-2,-1,1,2,1,2 }, dx[8] = { -2,-1,1,2,-2,-1,2,1 };
		deque<vector<int>>q;
		vector<int> t;
		t.push_back(0);
		t.push_back(sX);
		t.push_back(sY);
		q.push_back(t);
		Dist[sX][sY] = 0;
		while (!q.empty()) {
			int d, x, y;
			d = q.front()[0];
			x = q.front()[1];
			y = q.front()[2];
			q.pop_front();
			if (y == fY && x == fX)
			{
				cout << d <<"\n"; break;
			}
			int nextX, nextY;
			for (int i = 0; i < 8; i++) {
				nextX = x + dx[i];
				nextY = y + dy[i];
				if (nextY >= 0 && nextX >= 0 && nextX < L && nextY < L && Dist[nextX][nextY] == -1)
				{
					Dist[nextX][nextY] = Dist[x][y] + 1;
					vector<int> t;
					t.push_back(Dist[nextX][nextY]);
					t.push_back(nextX);
					t.push_back(nextY);
					q.push_back(t);
				}

			}
		}
	}
	return 0;
}
