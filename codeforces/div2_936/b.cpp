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


lint MOD = 1000000007LL;

void solve() {
	int n, k; cin >> n >> k;			
	vector<lint> v(n);
	lint sum_ = 0LL;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		sum_ += v[i];
	}
	lint cnt = 0LL;
	lint max_ = -(1LL << 60);
	for(int i = 0; i < n; i++) {
		cnt += v[i];
		if(cnt < 0LL) {
			cnt = 0;	
		}
		max_ = max(cnt, max_);
	}
	
	for(int i = 0; i < k; i++) {
		sum_ += max_;	
		sum_ = (sum_ + MOD) % MOD;
		max_ *= 2LL;
		max_ = (max_ + MOD) % MOD;
	}

	cout << sum_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
