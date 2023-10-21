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

struct cmp {
	bool operator () (vector<lint> v1, vector<lint> v2) {
		return v1[0] > v2[0];
	}
};

void solve() {
	lint n, a, b, c;		
	cin >> n >> a >> b >> c;

	lint dist[n+1][n+1];

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)	 {
			cin >> dist[i][j];
		}
	}

	priority_queue<vector<lint>, vector<vector<lint>>, cmp> pq;

	pq.push({0, 1, 0});

	vector<vector<lint>> dp(n+1, vector<lint>(2, 1LL << 60));
	dp[1][0] = 0;
	dp[1][1] = 0;

	while(!pq.empty()) {
		vector<lint> curr = pq.top();
		lint currDist = curr[0];
		lint currNode = curr[1];
		lint currState = curr[2];
		pq.pop();

		if(currDist > dp[currNode][currState]) continue;

		debug(curr);
		for(int i = 1; i <= n; i++) {
			debug(i);
			if(i == currNode) continue;
			if(currState == 0) {
			  if(currDist + a * dist[currNode][i] < dp[i][currState]) {
				  pq.push({currDist + a * dist[currNode][i], i, currState});
				  dp[i][0] = currDist + a * dist[currNode][i];
			  }
			  if(currDist + b * dist[currNode][i] + c < dp[i][currState|1]) {
				  pq.push({currDist + b * dist[currNode][i] + c, i, currState|1});
				  dp[i][1] = currDist + b * dist[currNode][i] + c;
			  }
				continue;
			}

			if(currDist + b * dist[currNode][i] + c < dp[i][1]) {
				pq.push({currDist + b * dist[currNode][i] + c, i, 1});
				dp[i][1] = currDist + b * dist[currNode][i] + c;
			}
		}
	}
	debug(dp);
	cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
