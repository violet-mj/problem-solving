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

struct cmp {
	bool operator() (vl& v1, vl& v2) {
		return v1[1] > v2[1];	
	}
};

void solve() {
	lint n; cin >> n;
	vector<vector<pll>> graph(n + 1);
	const lint INF = 1LL << 60;

	for(int i = 1; i < n; i++) {
		lint a, b, x;	
		cin >> a >> b >> x;
		graph[i].pb(mp(i + 1, a));
		graph[i].pb(mp(x, b));
	}

	priority_queue<vl, vector<vl>, cmp> pq;

	vl distance(n + 1, INF);
	distance[1] = 0LL;
	pq.push({1LL, 0LL});

	while(!pq.empty()) {
		vl curr = pq.top(); pq.pop();
		lint currNode = curr[0];
		lint currDist = curr[1];
		debug(currNode, currDist);

		if(currDist > distance[currNode]) continue;

		for(pll next: graph[currNode]) {
			if(currDist + next.s >= distance[next.f]) continue;
			distance[next.f] = currDist + next.s;
			pq.push({next.f, distance[next.f]});
		}
	}

	cout << distance[n] << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
