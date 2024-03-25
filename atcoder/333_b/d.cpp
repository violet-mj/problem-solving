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

vector<vector<int>> graph;
vector<int> visited;
vector<int> dp;

int dfs(int currNode) {
		debug(currNode);
		int cnt = 1;				
		visited[currNode] = 1;
		for(auto nextNode: graph[currNode]) {
			if(visited[nextNode])	continue;
			cnt += dfs(nextNode);
		}

		return dp[currNode] = cnt;
}

void solve() {
	int n;			
	cin >> n;

	graph.resize(n + 1, vector<int>());
	visited.resize(n + 1, 0);
	dp.resize(n + 1, 0);
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;	
		graph[a].pb(b);
		graph[b].pb(a);
	}
	debug(graph);
	dfs(1);
	debug(dp);

	vector<int> kk;

	for(int i = 0; i < graph[1].size(); i++) {
		kk.pb(dp[graph[1][i]]);
	}
	sort(all(kk));

	int cnt = 0;

	for(int i = 0; i < kk.size() - 1; i++) {
		cnt += kk[i];	
	}
	cout << cnt + 1;
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
