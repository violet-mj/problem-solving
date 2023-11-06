#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>

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
vector<int> a;
vector<int> b;
vector<int> visited;
int n, m;

bool dfs(int currNode, int color) {	
	if(visited[currNode] != -1) {
		if(color != visited[currNode]) return false;
		return true;
	}
	visited[currNode] = color;
	bool curr = true;
	for(int i = 0; i < graph[currNode].size(); i++) {
		curr &= dfs(graph[currNode][i], color ^ 1);
	}
	return curr;
}

void solve() {
	cin >> n >> m;
	graph.resize(n+1, vector<int>());
	a.resize(m);
	b.resize(m);
	visited.resize(n+1, -1);

	for(int i = 0; i < m; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];

	for(int i = 0; i < m; i++) {
		graph[a[i]].pb(b[i]);
		graph[b[i]].pb(a[i]);
	}

	for(int i = 1; i < n+1; i++) {
		if(visited[i] == -1)	 {
			if(!dfs(i, 1)) {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
