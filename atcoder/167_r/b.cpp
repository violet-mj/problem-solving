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

const lint MOD = 998244353;

lint mul(lint a, lint b) {
	if(b == 0LL) return 1LL;

	lint mid = mul(a, b/2);

	lint sqrtMid = mid * mid % MOD;

	return b % 2 == 1 ? sqrtMid * a % MOD : sqrtMid;
}

vector<int> erathos(int toNum) {
	int sqrtN = sqrt((lint) toNum);
	vector<bool> check(toNum + 1, true);
	for(int i = 2; i <= sqrtN; i++) {
		if(check[i]) {
			for(int j = 2 * i; j <= toNum; j += i)	 {
				check[j] = false;
			}
		}
	}

	vector<int> prime;

	for(int i = 2; i <= toNum; i++) {
		if(check[i]) {
			prime.pb(i);
		}
	}

	return prime;
}

void solve() {
	lint a, b;
	cin >> a >> b;
	vector<pll> factor;

	lint i = 2;
	lint sqrtA = (lint)sqrt(a) + 1;


	for(lint i = 2; i <= sqrtA; i++) {
		lint cnt = 0;	

		while(a % i == 0) {
			cnt++;
			a /= i;
		}
		if(cnt != 0) factor.pb(mp(i, cnt));
	}

	if(a != 1) factor.pb(mp(a, 1LL));
	lint modB = b % MOD;

	lint res = modB;
	lint bOdd = b % 2LL == 1LL;
	lint k = b & 1;

	for(pll f: factor) {
	  lint m = ((modB) * (f.s % MOD) + 1LL);
		m %= MOD;
		res *= m;
		res %= MOD;
		k &= f.s % 2 == 0;
	}
	if(k&1LL) res = (res - 1LL + MOD) % MOD;
	
	lint modinv = mul(2LL, MOD - 2LL);
	res *= modinv; 
	res %= MOD;


	cout << res  % MOD << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
