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

const int INF = 1 << 30;

void solve() {
	int n, m;		
	cin >> n >> m;
	int dist[n][n];
	vector<int> train(n);
	vector<pii> dp(n, mp(INF, INF));
	for(int i = 0; i < n; i++) cin >> train[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)	 {
			cin >> dist[i][j];
		}
	}
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0, 0, 0});
	while(!pq.empty()) { 
		vector<int> curr = pq.top();
		int transfer = curr[0];
		int move = curr[1];
		int currNode = curr[2];
		pq.pop();

		if(currNode == m) {
			cout << transfer << " " << move << "\n";
			return;
		}
		if(dp[currNode].f < transfer) continue;
		if(dp[currNode].f == transfer && dp[currNode].s < move) continue;

		for(int nextNode = 0; nextNode < n; nextNode++) {
			if(dist[currNode][nextNode] == 0) continue;
			int add = train[currNode] == train[nextNode] ? 0 : 1;
			if(dp[nextNode].first < transfer + add) continue;
			if(dp[nextNode].first == transfer + add && dp[nextNode].second < move + dist[currNode][nextNode]) continue;
			dp[nextNode].first = transfer + add;
			dp[nextNode].second = move + dist[currNode][nextNode];
			pq.push({dp[nextNode].first, dp[nextNode].second, nextNode});
		}
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
