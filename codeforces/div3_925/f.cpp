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
	int n, k;		
	cin >> n >> k;
	vector<vector<int>> order(k);
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			order[i].pb(tmp);
		}
	}

	set<pii> check;

	vector<vector<int>> graph(n + 1);
	vector<int> indegree(n + 1, 0);

	for(int i = 0; i < k; i++) {
		for(int j = 1; j < n - 1; j++)	 {
			if(check.find(mp(order[i][j], order[i][j+1])) != check.end()) continue;
			graph[order[i][j]].pb(order[i][j+1]);
			indegree[order[i][j+1]]++;
			check.insert(mp(order[i][j], order[i][j+1]));
		}
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 1; i <= n; i++) if(!indegree[i]) pq.push(i);
	vector<int> res;

	while(!pq.empty()) {
		int curr = pq.top(); pq.pop();	
		res.pb(curr);
		for(int i = 0; i < graph[curr].size(); i++) {
			int nxt = graph[curr][i];
			indegree[nxt]--;
			if(!indegree[nxt]) pq.push(nxt);
		}
	}

	if(res.size() == n) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
