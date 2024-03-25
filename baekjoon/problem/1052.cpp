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

int solve() {
	int res, n, k; cin >> n >> k;
	int cnt = 0; 		
	int curr1 = __builtin_popcount(n);
	if (curr1 <= k) {
			return 0;
	}

	bool flag = false;

	for (int i = 31; i >= 0; --i) {
			if ((n & (1 << i)) == 0) continue;
			if (flag) {
					res -= (1 << i);
			} else {
					cnt++;
					if (cnt == k) {
							flag = true;
							res = (1 << i);
					}
			}
	}
	return res;
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	cout << solve();
}
