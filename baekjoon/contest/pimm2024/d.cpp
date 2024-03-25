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

void solve() {
	int n, m, k; cin >> n >> m >> k;
	int dx[6] = {-1, -1, 0, 0, 1, 1};
	int dy[2][6] = {
		{-1, 0, -1, 1, -1, 0},
		{0, 1, -1, 1, 0 ,1}
	};
	vector<vector<int>> graph(n, vector<int>(m, 0));
	vector<vector<int>> visited(n, vector<int>(m, 0));
	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		graph[a][b] = 1;
	}

	queue<vector<int>> q;
	q.push({0, 0, 0});
	visited[0][0] = 1;

	while(!q.empty()) {
		vector<int> curr = q.front(); q.pop();
		int currx = curr[0];
		int curry = curr[1];
		int dist = curr[2];

		debug(curr);
		if(currx == n - 1 && curry == m - 1) {
			cout << dist << "\n";
			return;
		}

		for(int i = 0; i < 6; i++) {
			int nx = currx + dx[i];
			int ny = curry + dy[currx % 2][i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(visited[nx][ny] || graph[nx][ny]) continue;
			visited[nx][ny] = 1;
			q.push({nx, ny, dist + 1});
		}
	}
	
	cout << -1 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
