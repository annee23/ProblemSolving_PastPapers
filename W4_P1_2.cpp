#include<iostream>
#include<vector>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		int N, t; cin >> N;
		vector<int>choose;
		choose.push_back(-1);	//0번이아닌 1번부터시작하니까 
		vector<int>pair;
		pair.push_back(-1);
		pair.resize(N+1);
		for (int i = 0; i < N; i++) {// i+1번째 사람이 누굴 지목했는지 저장
			cin >> t;
			choose.push_back(t);
		}
		for (int i = 1; i < N + 1; i++) {
			if (pair[i] != 0)		//짝이 있으면 스킵
				continue;
			if (choose[i] == i)		//고른사람이 본인이면 2를 넣기(2의 의미는 혼자팀이라는것)
			{
				pair[i] = 2;
			}
			else
			{
				int tmp; bool boo = false;
				vector<int>v;
				tmp = choose[i];
				while (tmp != i)		//고른사람의 꼬리에 꼬리물어서 총 팀원 다 구하기
				{
					if (tmp == choose[tmp]) //끝이 혼자팀인 사람이면 팀 만들어지는게 무산됨
					{
						pair[i] = 0;
						boo = true;
						break;
					}
					else if(pair[tmp]!=0)   //고른사람이 혼자팀인 사람이여도 팀 만들어지는게 무산됨
					{
						pair[i] = 0;
						boo = true;
						break;
					}
					else
					{
						for (int j = 0; j < v.size(); j++)
							if(tmp==v[j])
							{
								pair[i] = 0;
								boo = true;
								break;
							}
						if (boo)
							break;
						v.push_back(tmp);
						tmp = choose[tmp];		//다음사람 지목
					}
				}
				if (!boo)
				{
					pair[i] = 1;			//팀이 있다.
					for (int j = 0; j < v.size(); j++)
						pair[v[j]] = 1;			//팀원들 모두에게 팀이있다는 의미인 1을 넣어줌
				}
			}
		}
		int count = 0;
		for (int i = 1; i < N + 1; i++) {	//팀이 없는사람 명수 구하기
			if (pair[i]==0)
				count++;
		}
		cout << count << "\n";
	}
}