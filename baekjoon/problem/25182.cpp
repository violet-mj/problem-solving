
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
 	vector<int> val(2*n + 1, 0);
 	const lint mod = 1e9 + 7;
 
	for(int i = 1; i <= 2 * n; i += 2) {
		 val[i] = (i + 1) / 2;
 	   val[i+1] = (i + 1) / 2;
 	}
	val.erase(val.begin());
	debug(val);
 	lint cnt = 0LL;

	vector<lint> result;
 
 	do {
 		vector<int> k(n + 1, -1);
 		vector<int> dp(2 * n + 1, 0);
 		for(int i = 1; i <= 2 * n; i++) {
 			dp[i]	= dp[i - 1] + val[i - 1];
 		}
 
 		lint res = 0LL;
 		for(int i = 1; i <= 2 * n; i++) {
 			if(k[val[i - 1]] == -1)	 {
 				k[val[i - 1]]	= i;
 			} else {
 				res += (dp[i] - dp[k[val[i - 1]] - 1]) * val[i - 1];
 				res %= mod;
 			}
 		}
		result.pb(res);
		if(res == 130) {
			debug(val);
		}
 	} while(next_permutation(all(val)));

	lint maxValue = *max_element(all(result));
	lint vvv = count(all(result), maxValue);
	debug(vvv, maxValue);
 }



void solve1() {
	lint n; cin >> n;
 	const lint mod = 1000000007LL;

	vector<lint> val(2 * n + 1, 0);
	vector<lint> dp(2 * n + 1, 0);

	for(lint i = n; i >= 1; i--){
		val[n - i + 1] = i;
		val[n + i] = i;
	}

	for(lint i = 1; i <= 2 * n; i++) {
		dp[i] = dp[i - 1]	 + val[i];
	}

	vector<int> k(n + 1, -1);
	lint res = 0LL;

	for(int i = 1; i <= 2 * n; i++) {
		if(k[val[i]] == -1)	 {
			k[val[i]]	= i;
		} else {
			res += (dp[i] - dp[k[val[i]] - 1]) * val[i];
			res %= mod;
		}
	}

	lint facto = 1LL;

	for(lint i = 1LL; i <= n; i++) {
		facto = facto * i % mod;
	}

	facto = facto * facto % mod;
	cout << res << " " << facto;
}

void solve2() {
	lint n; cin >> n;

	vector<lint> val(2 * n + 1, 0);
	vector<lint> dp(2 * n + 1, 0);

	for(lint i = n; i >= 1; i--){
		val[n - i + 1] = i;
		val[n + i] = i;
	}

	for(lint i = 1; i <= 2 * n; i++) {
		dp[i] = dp[i - 1]	 + val[i];
	}

	vector<int> k(n + 1, -1);
	lint res = 0LL;

	for(int i = 1; i <= 2 * n; i++) {
		if(k[val[i]] == -1)	 {
			k[val[i]]	= i;
		} else {
			res += (dp[i] - dp[k[val[i]] - 1]) * val[i];
		}
	}

	lint facto = 1LL;

	for(lint i = 1LL; i <= n; i++) {
		facto = facto * i;
	}

	facto = facto * facto;
	cout << res << " " << facto;
}
int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve2();
}
