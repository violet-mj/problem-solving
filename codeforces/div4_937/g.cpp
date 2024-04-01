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
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<lint> vl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

void solve() {
	int n; cin >> n;	
	
	map<string, vector<int>> genre;
	map<string, vector<int>> writer;

	vector<set<int>> graph(n);
	vector<pss> query;

	for(int i = 0; i < n; i++) {
		string g, w; cin >> g >> w;		
		genre[g].pb(i);
		writer[w].pb(i);
		query.pb(mp(g, w));
	}

	for(int i = 0; i < n; i++) {
		for(int gp: genre[query[i].f]) {
			if(gp == i)	continue;
			graph[i].insert(gp);
		}
		for(int wp: writer[query[i].s]) {
			if(wp == i)	continue;
			graph[i].insert(wp);
		}
	}

	vector<int> visited(n, 0);

	int max_ = 1;

		int component = 0;
		queue<vector<int>> q;	
		visited[0] = 1;
		q.push({0, 0});
		int maxDist = -1;
		int maxIdx = -1;

		while(!q.empty()) {
			vector<int> curr = q.front(); q.pop();		
			int currNode = curr[0];
			int currDist = curr[1];
			if(currDist > maxDist) {
				maxDist = currDist;
				maxIdx = currNode;
			}
			for(int nxt: graph[curr[0]]) {
				if(visited[nxt]) continue;
				visited[nxt] = 1;
				q.push({nxt, currDist + 1});
			}
		}


		component = 0;
		queue<vector<int>> qe;
		visited.clear();
		visited[0] = 1;
		q.push({0, 0});
		maxDist = -1;
		maxIdx = -1;

		while(!qe.empty()) {
			vector<int> curr = qe.front(); qe.pop();		
			int currNode = curr[0];
			int currDist = curr[1];
			if(currDist > maxDist) {
				maxDist = currDist;
				maxIdx = currNode;
			}
			for(int nxt: graph[curr[0]]) {
				if(visited[nxt]) continue;
				visited[nxt] = 1;
				qe.push({nxt, currDist + 1});
			}
		}


		cout << n - maxDist << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
