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


vector<lint> erathos(int toNum) {
	int sqrtN = sqrt((lint) toNum);
	vector<bool> check(toNum + 1, true);
	for(int i = 2; i <= sqrtN; i++) {
		if(check[i]) {
			for(int j = 2 * i; j <= toNum; j += i)	 {
				check[j] = false;
			}
		}
	}

	vector<lint> prime;

	for(int i = 2; i <= toNum; i++) {
		if(check[i]) {
			prime.pb((lint)i);
		}
	}

	return prime;
}

void solve() {
	lint n; cin >> n;
	vector<lint> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<lint> prime = erathos(1000);

	for(int i = 0; i < prime.size(); i++) {
		int ps = prime[i] * prime[i];
		for(int j = 0; j < n; j++)	 {
			if(v[j] == 0) continue;
			while(v[j] % ps == 0)	 {
				v[j] /= ps;	
			}
		}
	}

	map<lint, lint> k; 

	for(int i = 0; i < n; i++) {
		k[v[i]]++;
	}

	lint res = (lint)k[0] * (lint)(n - k[0]);
	debug(res);

	debug(k);
	for(auto val: k) {
		res += (lint) val.s * (val.s - 1LL) / 2LL;
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
