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
vector<vector<pii>> graph;
vector<lint> visited;
vector<lint> dp;
vector<lint> rdist;
int n;
int maxDist = -1;
int maxNode = -1;

void dfs(int currNode, int currDist) {
	if(currDist > maxDist)	 {
		maxNode = currNode;	
		maxDist = currDist;
	}
	visited[currNode] = 1;
	for(pii nextNode: graph[currNode]){
		if(!visited[nextNode.f]) {
			dfs(nextNode.f, currDist + nextNode.s);
		}
	}
}

int dfs2(int currNode, int currDist) {
	lint max_ = 0;
	rdist[currNode] = currDist;
	visited[currNode] = 1;
	for(pii nextNode: graph[currNode]) {
		if(!visited[nextNode.f]) max_ = max((lint)dfs2(nextNode.f, currDist + nextNode.s) + nextNode.s, (lint)max_);
	}
	return dp[currNode] = max_;
}

void solve() {
	cin >> n;
	graph.resize(n + 1);
	visited.resize(n+1,0);
	rdist.resize(n+1, 0);
	dp.resize(n+1, -1);

	for(int i = 0; i < n - 1; i++) {
		int a,b,c; cin >> a >> b >> c;			
		graph[a].pb(mp(b, c));
		graph[b].pb(mp(a, c));
	}
	dfs(1, 0);

	visited = vector<lint>(n+1, 0);
	dfs2(maxNode, 0);

	for(int i = 1; i <= n; i++) {
		cout << max(dp[i], rdist[i]) << "\n";
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
