#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

int n, m, tmp;
string s;


void solve() {	
	cin >> n >> m >> s;
	vector<vector<int>> coloring(m + 1);
	char k[n];
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		coloring[tmp].pb(i);
	}

	for(int i = 1; i <= m; i++) {
		k[coloring[i][0]] = s[coloring[i][coloring[i].size() - 1]];
		for(int j = 1; j < coloring[i].size(); j++ ) {
			k[coloring[i][j]] = s[coloring[i][j-1]];
		}	
	}

	for(int i = 0; i < n; i++) {
		cout << k[i];
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
