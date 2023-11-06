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

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void solve() {
	int n, k, s, x, y;		
	cin >> n >> k;
	int graph[n][n];
	queue<vector<int>> q;
	vector<vector<int>> nodes;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin	>> graph[i][j];
			if(graph[i][j] > 0) nodes.pb({i, j, graph[i][j]});
		}
	}

	cin >> s >> x >> y;

	sort(all(nodes), [](vector<int> v1, vector<int> v2) {
		return v1[2] < v2[2];	
	});

	for(int i = 0; i < nodes.size(); i++) {
		vector<int> tmp = nodes[i];
		q.push({tmp[0], tmp[1], tmp[2], 0});
	}

	while(!q.empty()) {
		auto currNode = q.front();
		int cx = currNode[0];
		int cy = currNode[1];
		int cv = currNode[2];
		int cnt = currNode[3];
		q.pop();

		if(cnt >= s) continue;
	
		for(int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if(graph[nx][ny] > 0) continue;
			graph[nx][ny] = cv;
			q.push({nx, ny, cv, cnt + 1});
		}
	}
	cout << graph[x-1][y-1] << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
