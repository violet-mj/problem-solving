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

lint exp2mod[300001];
const lint MOD = 1000000007LL;

void init() {
	fill(exp2mod, &exp2mod[300000], 0LL);
	exp2mod[0] = 1LL;
	for(int i = 1; i < 300001; i++) {
		exp2mod[i] = exp2mod[i-1] * 2LL % MOD;
	}
}

void solve() {
	int n;		
	cin >> n;
	init();
	vector<lint> sco(n + 1, 0LL);
	vector<lint> pre(n + 1, 0LL);
	for(int i = 1; i <= n; i++) {
		cin >> sco[i];
	}
	sort(all(sco));
	for(int i = 1; i <= n; i++) {
		pre[i] = (pre[i-1] + sco[i]) % MOD;
	}

	debug(sco, pre);

	lint cnt = 0LL;

	for(int i = 1; i < n; i++) {
		cnt = (cnt + (pre[n] - pre[i] - pre[n - i] + 2 * MOD) * exp2mod[i - 1] ) % MOD;
	}

	cout << cnt % MOD << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
