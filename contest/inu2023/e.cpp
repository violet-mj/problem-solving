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
	int n, s, e;			
	cin >> n >> s >> e;
	vector<vector<int>> graph(n + 1);
	vector<int> visited(n + 1, 0);
	vector<int> depth(n + 1, -1);

	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	function<void(int, int, int)> dfs;

	dfs = [&depth, &graph, &visited, &n, &s, &e, &dfs](int currNode, int currDepth, int turn) {
		if(visited[currNode])	return;
		visited[currNode] = 1;
		depth[currNode] = currDepth;

		if(turn == 0 && graph[currNode].size() > 2) return;

		for(int nextNode: graph[currNode]) {
			if(visited[nextNode])	continue;
			dfs(nextNode, currDepth + 1, turn ^ 1);
		}
	};

	dfs(s, 0, 1);

	debug(depth);

	if(depth[e] == -1) {
		cout << "Second\n";
	} else {
		cout << "First\n";
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
