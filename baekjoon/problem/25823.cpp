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

int m;
lint fact[400001];
const lint MOD = 1000000007;

void factorial() {
	fact[0] = 1; fact[1] = 1;
	
	for(int i = 2; i <= 400000; i++) {
		fact[i] = fact[i-1] * i % MOD;
	}
}

lint mul(lint a, lint b) {
	if(b == 0) return 1;
	lint mid = mul(a, b/2);
	lint midSquare = mid * mid % MOD;
	return b % 2 == 1 ? midSquare * a % MOD : midSquare;
}

void solve() {
	cin >> m;
	lint res = 0;
	factorial();
	for(int i = 3; i <= m; i++) {
		// 100cout << fact[2 * i] << " " << fact[i] << "\n";
		res += fact[2 * i] * mul(fact[i] * fact[i] % MOD, MOD - 2);
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
