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
	bool operator() (vector<lint> v1, vector<lint> v2) {
		return v1[2] > v2[2];	
	}
};

const lint INF = 1LL << 60;

void solve() {
	lint n, m, k;		
	cin >> n >> m >> k;

	vector<vector<pll>> graph(n + 1);

	for(int i = 0; i < m; i++) {
		lint s, e, c; cin >> s >> e >> c;
		graph[s].pb(mp(e, c));
		graph[e].pb(mp(s, c));
	}

	vector<lint> elevator(n+1, 0);

	for(int i = 1; i <= n; i++) {
		lint ele; cin >> ele;	
		elevator[i] = ele;
	}
	priority_queue<vector<lint>, vector<vector<lint>>, cmp> pq;

	pq.push({1, 1, 0, 0});
	vector<vector<lint>> dp(n+1, vector<lint>(2, INF));
	dp[1][0] = 0LL;

	while(!pq.empty()) {
		vector<lint> curr = pq.top();
		debug(curr);
		pq.pop();
		lint currNode = curr[0];
		lint currFloor= curr[1];
		lint currTime = curr[2];
		lint currState = curr[3];

		if(currTime > dp[currNode][currState]) continue;

		if(currNode == n && currFloor == k) {
			cout << currTime << "\n";
			return;
		}

		if(!currState && elevator[currNode] != -1)	 {
			pq.push({currNode, currFloor + k - 1, currTime + (k - 1) * elevator[currNode], currState ^ 1});	
		}

		for(pll next_: graph[currNode]) {
			lint nextNode = next_.f;
			lint nextTime = next_.s;
			if(currTime + nextTime >= dp[nextNode][currState])	continue;
			dp[nextNode][currState] = currTime + nextTime;
			pq.push({nextNode, currFloor, dp[nextNode][currFloor], currState});
		}
	}

	cout << -1 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
