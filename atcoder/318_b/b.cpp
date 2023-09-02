#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/Users/mj/.vim/template/debug.cpp"
#else
#define debug(x...)
#endif

typedef long long lint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

// 정수가 int형의 범위를 넘어가는지
// integer overflow 확인
// 정방향이 아닌 역방향도 생각해보기
void solve() {
	int n, ai, bi, ci, di;
	cin >> n;
	bool sheet[101][101];	
	fill(&sheet[0][0], &sheet[100][101], false);

	for(int i = 0; i < n; i++)	 {
		cin >> ai >> bi >> ci >> di;	
		for(int j = ai; j < bi; j++) {
			for(int z = ci; z < di; z++)	 {
				sheet[j][z] = true;	
			}
		}	
	}

	int cnt = 0;

	for(int i = 0; i < 101; i++) {
		for(int j = 0; j < 101; j++) {
			if(sheet[i][j]) cnt++;	
		}	
	}

	cout << cnt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
