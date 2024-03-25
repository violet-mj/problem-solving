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

void solve(int n, int tn) {
	vector<pii> graph;		

	for(int i = 0; i < n - 1; i++) {
		int a, b;	 cin >> a >> b;
		graph.pb(mp(a, b));
	}

	auto check = [&](vector<pii>& sGraph) {
		vector<vector<int>> g(n+1);
		int init = -1;
		for(auto [s, e]: sGraph)	{
			if(init == -1) init = s;
			g[s].pb(e);
			g[e].pb(s);
		}
		vector<int> visited(n+1, 0);
		visited[init] = 1;
		queue<int> q;
		q.push(init);
		int c = n;
		while(!q.empty()) {
				int curr = q.front();		
				q.pop();
				c++;
				for(int num: g[curr]) {
					if(visited[num]) continue;
					visited[num] = 1;
					q.push(num);
				}
		}
		return c == sGraph.size() + 1 ? 1 : 0;

		if(c == sGraph.size() + 1) {
			debug(g);
			return 1;	
		}
		return 0;
	};

	int cnt = n;

	for(int i = 0; i < (1 << (n - 1)); i++) {
		debug(cnt);
		vector<pii> subGraph;
		for(int j = 0; j < n - 1; j++)	 {
			if((i & (1 << j)) != 0)		{
				subGraph.pb(graph[n - 2 - j]);
			}
		}
		int ss = subGraph.size();
		set<int> ns;
		for(auto [a, b]: subGraph) {
			ns.insert(a);
			ns.insert(b);
		}
		debug(i, ns, ss);
		cnt += ns.size() - 1 == ss ? 1 : 0;
	}
	cout << "Case " << tn << ": " << cnt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int cnt = 1;
	while(1) {
		int n; cin >> n;	
		if(n == 0) break;
		solve(n, cnt);
		cnt++;
	}
}
