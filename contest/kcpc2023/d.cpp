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

const lint INF = 1LL << 60;

void solve() {
	int n;		
	cin >> n;

	vector<int> ai(n);
	vector<int> bi(n);
	vector<int> xi(n);

	for(int i = 0; i < n; i++) cin >> ai[i];
	for(int i = 0; i < n; i++) cin >> bi[i];
	for(int i = 0; i < n; i++) cin >> xi[i];

	vector<int> res;

	for(int i = 0; i < n; i++) {
		if(abs(bi[i] - ai[i]) % xi[i] != 0)	 {
			cout << -1 << "\n"; return;
		}
		res.pb(abs(bi[i] - ai[i]) / xi[i]);
	}

	int parity = res[0] % 2;

	lint max_ = res[0];

	for(int i = 1; i < n; i++) {
		if(parity != res[i] % 2) {
			cout << -1 << "\n"; return;
		}
		max_ = max(max_, (lint)res[i]);
	}

	cout << max_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
