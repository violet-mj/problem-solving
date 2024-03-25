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

vector<int> visited;
vector<vector<int>> graph;
vector<int> dp;

void dfs(int currNode) {
	visited[currNode] = 1;
	for(auto nextNode: graph[currNode]) {
		if(visited[nextNode])	 continue;
		dfs(nextNode);
		dp[currNode]++;
	}
}

void solve() {
	int n; cin >> n;
	graph.clear();
	visited.clear();
	dp.clear();
	graph.resize(n + 1);
	visited.resize(n + 1, 0);
	dp.resize(n + 1, 0);

	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;	
		graph[a].pb(b);
		graph[b].pb(a);
	}
	dfs(1);
	int cnt = 0;
	int idx = max_element(all(dp)) - dp.begin();
	visited.clear();
	dp.clear();
	visited.resize(n + 1, 0);
	dp.resize(n + 1, 0);
	dfs(idx);
	for(int i = 1; i <= n; i++) {
		if(dp[i] == 0) cnt++;
	}
	cout << (cnt + 1) / 2 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
