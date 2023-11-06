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
	int v, e;
	cin >> v >> e;
	vector<vector<int>> graph(v + 1, vector<int>());
	vector<int> visited(v + 1, -1);
	int a, b;
	for(int i = 0; i < e; i++) {
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	function<bool(int, int)> dfs;

	dfs = [&graph, &visited, &dfs](int currNode, int color) -> bool {
		bool init = true;
		if(visited[currNode] != -1)	 {
			if(color != visited[currNode]) {
				return false;	
			}
			return true;
		}
		visited[currNode] = color;
		for(int i = 0; i < graph[currNode].size(); i++) {
			init &= dfs(graph[currNode][i], color ^ 1);
		}

		return init;
	};

	for(int i = 1; i <= v; i++) {
		if(visited[i] == -1 && !dfs(i, 0)) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
		solve();
}
