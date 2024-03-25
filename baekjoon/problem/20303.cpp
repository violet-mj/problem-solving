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
	vector<int> candy(n + 1);
	vector<int> visited(n + 1, 0);
	vector<vector<int>> graph(n + 1);
	for(int i = 1; i <= n; i++) cin >> candy[i];
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;	
		graph[a].pb(b);
		graph[b].pb(a);
	}

	function<void(int)> dfs;

	debug(graph);

	int cnt = 0;
	int candyCnt = 0;

	dfs = [&candyCnt, &cnt, &dfs, &visited, &candy, &graph] (int currNode) {
		visited[currNode]	= 1;
		cnt++;
		candyCnt += candy[currNode];

		for(int nextNode: graph[currNode]) {
			if(visited[nextNode]) continue;
			dfs(nextNode);
		}
	};

	vector<pair<int, int>> group;

	for(int i = 1; i <= n; i++) {
		if(visited[i]) continue;
		cnt = 0;
		candyCnt = 0;
		dfs(i);
		group.pb(mp(cnt, candyCnt));
	}

	debug(group);

	vector<int> dp(k, 0);

	for(int i = 1; i <=  group.size(); i++) {
		pii currGroup = group[i-1];
		for(int j = k - 1; j >= currGroup.f; j--)	 {
			dp[j] = max(dp[j - currGroup.f] + currGroup.s, dp[j]);
		}
	}

	debug(dp);
	cout << dp[k - 1] << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
