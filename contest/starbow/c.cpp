
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

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
typedef vector<int> vi;
typedef vector<lint> vl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solve() {
	int n, m;		
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m));
	vector<int> rows(n, 0);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> graph[i][j];

	auto check = [&](int x, int y) {
		int dir = 0;
		int currX = x;	
		int currY = y;	
		int cnt = 0;
		while(cnt < 40001) {
			int nextX = currX + graph[currX][currY]	* dx[dir % 4];
			int nextY = currY + graph[currX][currY]	* dy[dir % 4];
			if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) return false;
			currX = nextX;
			currY = nextY;
			dir++;
			cnt++;
		}
		return true;
	};

	int res = 0;
		for(int j = 0; j < n; j++)	 {
			if(check(j, 0)) {
				rows[j] = 1;
				res++;
			}
	}

	cout << res << "\n";
	for(int i = 0; i < n; i++) {
		if(rows[i] == 1) cout << i + 1 << " ";	
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
