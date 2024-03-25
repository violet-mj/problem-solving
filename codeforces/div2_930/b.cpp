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
	vector<string> graph(2);
	for(int i = 0; i < 2; i++) {
		cin >> graph[i];
	}

	int idx = -1;
	int cnt = 1;

	for(int i = 0; i < n - 1; i++) {
		if(graph[1][i] == '0' && graph[0][i+1] == '1')  {
			idx = i; break;	
		} else if(graph[1][i] == '1' && graph[0][i+1] == '0') {
			cnt = 1;
		} else {
			cnt++;	
		}
	}

	if(idx == -1) {
		idx = n - 1;	
	}

	int init = 0;

	vector<char> res;

	for(int i = 0; i < n; i++) {
		if(i == idx)	 {
			init = 1;	
			res.pb(graph[0][i]);
			res.pb(graph[1][i]);
			debug(i, res);
			continue;
		}
		res.pb(graph[init][i]);
		debug(i, res);
	}

	for(int i = 0; i < n + 1; i++) {
		cout << res[i];
	}
	cout << "\n";
	cout << cnt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
