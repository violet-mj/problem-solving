
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

int t, v, e, l_, r_;
int dp[10001];
vector<vector<int>> rTree(10001);
int node[10001];
int tree[10001];

int dfs(int curr, int level) {
	node[curr] = level;
	if(dp[curr] != 0) {
		return dp[curr];
	}
	if(rTree[curr].size() == 0) {
		dp[curr] = 1;
		return 1;	
	}

	int tmp = 0;

	for(auto nextNode: rTree[curr]) {
		tmp += dfs(nextNode, level + 1);
	}
	dp[curr] = tmp + 1;
	return dp[curr];
}


void solve(int tn) {
	cin >> v >> e >> l_ >> r_;

	int parent, child;
	fill(node, &node[10001], 0);
	fill(tree, &tree[10001], 0);
	fill(dp, &dp[10001], 0);

	tree[1] = 1;

	for(int i = 0; i < e; i++) {
		cin >> parent >> child;							
		int parentLevel = node[parent];
		tree[child] = parent;
		rTree[parent].pb(child);
	}

	dfs(1, 1);

	int l, r;
	
	l = min(l_, r_);
	r = max(l_, r_);
	if(debug) cout << "l " << l << " r " << r << "\n" ;

	while(node[l] != node[r])	{
		r = tree[r];
	}

	if(debug) {
		cout << "node" << "\n";
		for(int i = 1; i <= v; i++) cout << node[i] << " ";
		cout <<"\n";
		cout << "dp" << "\n";
		for(int i = 1; i <= v; i++) cout << dp[i] << " ";
		cout << "\n";
	}

	if(debug) cout << "l " << l << " r " << r << "\n" ;

	while(l != r) {
		if(debug) cout << "l " << l << " r " << r << "\n" ;
		l = tree[l];
		r = tree[r];
	}

	if(debug) cout << "l " << l << " r " << r << "\n" ;

	cout << "#" << tn << " " << l << " " << dp[l] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		solve(i);
	}
}
