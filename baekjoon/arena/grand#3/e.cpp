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
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
const lint MOD = 998244353LL;
vector<lint> factorials;
vector<lint> factorial() {
	vector<lint> facto(1000000, 0);
	facto[0] = 1LL;
	facto[1] = 1LL;
	for(lint i = 2; i <= 1000000; i++) {
		facto[i] = (lint)facto[i-1] * i % MOD;
	}
	return facto;
}

lint mul(lint a, lint b) {
	if(b == 0) return 1;
	lint dnc = mul(a, b / 2);
	if(b % 2 == 1) {
		return (lint)(dnc * dnc) % MOD * a % MOD;
	} else {
		return (lint)dnc * dnc % MOD;	
	}
}

int combination(int n, int k) {
	int nf = factorials[n];
	int kf = factorials[k];
	int nkf = factorials[n - k];
	int knkf = (lint) kf * nkf % MOD;
	return (lint) nf * mul(knkf, MOD - 2LL) % MOD;
}

void solve() {
	lint n;	
	cin >> n;
	vector<vector<int>> allS(n);
	map<int, int> mm;
	factorials = factorial();
	lint allSum = 0LL;
	for(int i = 0; i < n; i++) {
		lint sn;	cin >> sn;
		for(int j = 0; j < sn; j++) {
			int tmp; cin >> tmp;
			allS[i].pb(tmp);
			mm[tmp]++;
		}
	}

	for(lint i = 1LL; i <= n; i++) {
		lint sum_ = 0LL;
		vector<int> removal;
		for(auto j = mm.begin(); j != mm.end(); j++) {
			lint v = j->f;
			lint cnt = j->s;
			if(cnt < i) {
				removal.pb(v);
			} else {
				sum_ += combination((lint)cnt, i);
				sum_ %= MOD;
			}
		}

		for(auto v: removal) {
			mm.erase(v);
		}
		cout << sum_ << "\n";
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
