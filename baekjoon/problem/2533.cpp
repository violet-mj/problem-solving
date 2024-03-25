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
	int n;		
	cin >> n;
	vector<vector<int>> graph(n+1);
	vector<vector<int>> dp(n+1, vector<int>(2, 0));
	vector<int> visited(n + 1, 0);
	
	function<void(int)>	dfs;

	dfs = [&graph, &dp, &visited, &dfs](int currNode) {
		if(visited[currNode])	return;
		visited[currNode] = 1;
		int cnt0 = 0;
		int cnt1 = 0;
		for(int nextNode: graph[currNode]) {
			if(visited[nextNode]) continue;
			dfs(nextNode);
			cnt0 += min(dp[nextNode][0], dp[nextNode][1]);
			cnt1 += dp[nextNode][1];
		}

		dp[currNode][0] = cnt1;
		dp[currNode][1] = cnt0 + 1;
	};
		
	for(int i = 0; i < n - 1; i++) {
		int a, b;	cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	dfs(1);

	debug(dp);

	cout << min(dp[1][0], dp[1][1]) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
