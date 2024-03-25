#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <stack>

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
vector<vector<int>> SCC;
vector<int> dfsn;
vector<int> finished;
stack<int> stk;
vector<int> sn;
int n, edge, s, e;
int cnt, SN;

int dfs(int curr) {
	dfsn[curr] = ++cnt;
	stk.push(curr);

	int result = dfsn[curr];
	for(int next: graph[curr]) {
		if(dfsn[next] == 0)	 result = min(result, dfs(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}

	if(result == dfsn[curr]) {
		vector<int> currSCC;
		while(1) {
			int t = stk.top();
			stk.pop();
			currSCC.pb(t);
			finished[t] = true;
			sn[t] = SN;
			if(t == curr) break;
		}
		sort(all(currSCC));
		SCC.pb(currSCC);
		SN++;
	}
	return result;
}

void solve() {
	finished = vector<int>();
	dfsn = vector<int>();
	sn = vector<int>();
	SCC = vector<vector<int>>();
	graph = vector<vector<int>>();
	stk = stack<int>();
	cin >> n >> edge;
	cnt = 0; SN = 0;
	graph.resize(n+1);
	dfsn.resize(n+1, 0);
	finished.resize(n+1, false);
	sn.resize(n+1, -1);

	for(int i = 0; i < edge; i++) {
		cin >> s >> e;
		graph[s].pb(e);
	}

	for(int i = 1; i <= n; i++) {
		if(dfsn[i] == 0)	dfs(i);
	}

	vector<int> inDegree(SCC.size(),  0);

	for(int i = 1; i <= n; i++) {
		for(int j: graph[i])	 {
			if(sn[i] != sn[j]) inDegree[sn[j]]++;
		}
	}

	int res = 0;

	for(int i = 0; i < inDegree.size(); i++) {
		if(inDegree[i] == 0)	res++;
	}

	cout << res << "\n";
}


int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
