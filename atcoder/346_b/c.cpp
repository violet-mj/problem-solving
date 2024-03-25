
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
	lint n, k; cin >> n >> k;		
	vector<lint> v(n);
	set<lint> ss;

	for(int i = 0; i < n; i++) {
		cin >> v[i];
		if(v[i] >= 1 && v[i] <= k) {
			ss.insert(v[i])	;
		}
	}

	lint sum_ = k * (k + 1) / 2LL;

	for(auto i: ss) {
		sum_ -= i;
	}

	cout << sum_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
