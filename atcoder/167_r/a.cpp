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

void solve() {		
	int n, m;
	cin >> n >> m;

	vector<int> toast(n);
	lint res = 0LL;
	for(int i =0 ; i < n; i++) {
		cin >> toast[i];
		res += (lint)toast[i] * toast[i];
	}

	int diff = n - m;

	int l = 0;
	int r = (n - m) * 2 - 1;
	sort(all(toast));
	debug(toast, l, r, res);
	while(l < r) {
		debug(toast[l], toast[r]);
		res += (lint)2 * toast[l] * toast[r];
		l++; r--;
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
