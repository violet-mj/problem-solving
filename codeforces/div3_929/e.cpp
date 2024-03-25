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
	vector<int> v(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	vector<lint> pre(n + 1, 0);

	for(int i = 1;i <= n; i++) {
		pre[i] = pre[i - 1]	 + (lint)v[i];
	}

	int q; cin >> q;

	auto check = [&](int lv, int mid, int u) {
		return pre[mid] - pre[lv - 1] < u ? true : false;
	};

	for(int i = 0; i < q; i++) {
		int l, u; cin >> l >> u;
		int r = n;

		while(l + 1 < r) {
			int mid = (l + r)	>> 1;
			if(check(l, mid, u)) {
				l = mid;
			} else {
				r = mid;
			}
		}

		debug("r = ", r);
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
