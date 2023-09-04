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

const lint MOD = 1000000007LL;
pll endPoint;
vector<pll> bombs;
vector<pll> check = {{0LL, 0LL}};
lint n, m, k, x, y;	
vector<lint> fact;
vector<lint> inv_fact;
vector<lint> inv_fact2;
lint res = 1LL;

void factorial() {
	fact.resize(2000001);
	fact[0] = 1LL; fact[1] = 1LL;
	for(lint i = 2LL; i <= 2000000LL; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}
}

void factorialInverse() {
	inv_fact.resize(2000001);
	inv_fact[0] = 1LL;
	inv_fact[1] = 1LL;
	for(lint i = 2L; i <= 2000000LL; i++) {
		inv_fact[i] = inv_fact[MOD % i] * (MOD - (MOD / i)) % MOD;
	}
}

void fI() {
	inv_fact2.resize(2000001);
	inv_fact2[0] = 1LL;
	inv_fact2[1] = 1LL;
	for(lint i = 2LL; i <= 2000000LL; i++) {
		inv_fact2[i] = inv_fact2[i - 1] * inv_fact[i] % MOD;
	}
}

void backtracking(int curr) {
	lint kk = 1LL;
	int last = check.size();
	check.pb(mp(n, m));
	for(int i = 0; i < last; i++)	{ 
		lint dx = check[i+1].f - check[i].f;
		lint dy = check[i+1].s - check[i].s;
		kk *= fact[dx + dy];
		kk %= MOD;
		kk *= inv_fact2[dy];
		kk %= MOD;
		kk *= inv_fact2[dx];
		kk %= MOD;
	}
	check.pop_back();
	if(last % 2 == 0) {
		res = (res + MOD - kk) % MOD;	
	} else {
		res += kk;	
	}

	for(int i = curr + 1; i < k; i++)	{
		if(bombs[curr].s > bombs[i].s) continue;			
		check.pb(bombs[i]);
		backtracking(i);
		check.pop_back();
	}
}

void solve() {
		cin >> n >> m >> k;
		endPoint = mp(n, m);
		factorial();
		factorialInverse();
		fI();
		res *= fact[n + m];
		res %= MOD;
		res *= inv_fact2[m];
		res %= MOD;
		res *= inv_fact2[n];
		res %= MOD;
		for(int i = 0; i < k; i++) {
			cin >> x >> y;
			bombs.pb(mp(x, y));
		}

		sort(all(bombs));

		for(int i = 0; i < k; i++)	 {
			check.pb(bombs[i]);
			backtracking(i);
			check.pop_back();
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
