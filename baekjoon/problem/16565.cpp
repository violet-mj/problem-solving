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

const lint MOD = 10007LL;
vector<int> factorials;

vector<int> factorial() {
	vector<int> facto(53, 0);
	facto[0] = 1;
	facto[1] = 1;

	for(int i = 2; i <= 52; i++) {
		facto[i] = (lint)facto[i - 1] * i % MOD;
	}

	return facto;
}

lint mul(int a, int b) {
	if(b == 0) return 1;
	int divMul = mul(a, b / 2);
	int dualMul = (lint) divMul * divMul % MOD;
	if(b%2==1) dualMul = (lint) dualMul * a % MOD;
	return dualMul;
}

int combination(int n, int k) {
	return (lint) factorials[n]	* mul((lint)factorials[n-k] * factorials[k] % MOD, MOD - 2) % MOD;
}

void solve() {
	int n;						
	cin >> n;
	factorials = factorial();
	lint res = 0LL;

	int pairs = n / 4;

	for(int i = 1; i < (1 << 13); i++)	 {
		int oneCount = __builtin_popcount(i);	
		if(oneCount > pairs) continue;
		debug(i, res);
		int remainCard = 52 - 4 * oneCount;
		int flag = oneCount % 2 == 0 ? -1 : 1;
		res += combination(remainCard, n - 4 * oneCount) * flag + MOD;
		res %= MOD;
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
