#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <functional>

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
	int n, k;		
	cin >> n >> k;
	vector<vector<int>> graph(n + 1);
	vector<int> visited(n + 1, 0);
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;	
		graph[a].pb(b);
		graph[b].pb(a);
	}

	function<int(int, int)> dfs;

	int check = 0;

	dfs = [&n, &k, &graph, &visited, &check, &dfs](int curr, int target) -> int {
		visited[curr] = 1;
		int cnt = 1;
		for(auto nxt: graph[curr]) {
			if(visited[nxt]) continue;
			cnt += dfs(nxt, target);
		}

		if(cnt >= target && check < k) {
			check++;
			return 0;	
		} else {
			return cnt;	
		}
	};


	int l = 1;
	int r = 100001;

	while(l + 1 < r) {
		int mid = (l + r) >> 1;
		check = 0;
		visited.assign(n + 1, 0);
		if(dfs(1, mid) < mid) {
			r = mid;	
		} else {
			l = mid;	
		}
	}
	cout << l << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
