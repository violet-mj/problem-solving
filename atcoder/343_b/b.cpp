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
	int n; cin >> n;
	int graph[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	vector<vector<int>> G(n);

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++)	 {
			if(graph[i][j] == 1)	 {
				G[i].pb(j);
				G[j].pb(i);
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j: G[i])	 {
			cout << j + 1 << " ";
		}
		cout << "\n";
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
