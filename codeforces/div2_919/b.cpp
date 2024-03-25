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
	int n, k, x; cin >> n >> k >> x;			
	vector<int> values(n);

	for(int i = 0; i < n; i++) cin >> values[i];
	sort(all(values));

	for(int i = n - 1; i >= max(0, n - x); i--) {
		values[i] *= -1;	
	}

	int cnt = 0;

	for(int i = 0; i < n; i++) {
		cnt += values[i];
	}
	int res = cnt;
	for(int i = n - 1; i >= max(n - k, 0); i--) {
		values[i] *= -1;	
		cnt += values[i];
		if(i - x >= 0) {
			values[i-x] *= -1;	
			cnt += 2 * values[i-x];
		}
		res = max(res, cnt);
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
