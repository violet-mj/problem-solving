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
	int n, k; cin >> n >> k;
	vector<int> v(n + 1, 0);
	vector<int> pre(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		pre[i] = pre[i - 1] + v[i];
	}
	debug(pre);
	
	int res = -(1 << 30);
	
	for(int i = k; i <= n; i++) {	
		res = max(res, pre[i] - pre[i - k]);
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
