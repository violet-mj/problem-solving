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

const lint INF = 1LL << 60;

void solve() {
	int n;
	cin >> n;
	vector<int> values(n + 1, 0);
	vector<lint> pre(n + 1, 0);
	vector<int> check;
	for(int i = 1; i <= n; i++) cin >> values[i];
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + values[i];
	}

	for(int i = 1; i <= (int)sqrt(n); i++) {
		if(n % i == 0)	 {
			check.pb(i);
			if(i != n / i) check.pb(n / i);
		}
	}

	lint res = 0;

	for(auto c: check) {
		lint max_ = -INF;
		lint min_ = INF;
		for(int i = c; i <= n; i+=c)	 {
			lint values = pre[i] - pre[i - c];
			max_ = max(max_, values);
			min_ = min(min_, values);
		}
		res = max(res, max_ - min_);
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
