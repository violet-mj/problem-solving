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

	int n, m; cin >> n >> m;
	vector<int> v1(n);
	vector<int> v2(m);
	for(int i = 0; i < n; i++) cin >> v1[i];
	for(int i = 0; i < m; i++) cin >> v2[i];
	sort(all(v1)); sort(all(v2));

	lint sum_ = 0;
	lint res = 0;

	for(int i = 0; i < n; i++) {
		sum_ += abs(v1[i] - v2[m - 1 - i]);
	}
	res = max(res, sum_);

	for(int i = n - 1; i >= 0; i--) {
		debug(res);
		int init = abs(v1[i] - v2[m - 1 - i]);
		int nxt = abs(v1[i] - v2[n - 1 - i]);
		sum_ += nxt - init;
		res = max(res, sum_);
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
