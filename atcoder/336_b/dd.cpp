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
	vector<int> values(n);
	for(int i = 0; i < n; i++) cin >> values[i];
	
	int init = 1;	
	int res = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(values[i] >= init)	 {
			cnt++;		
			res = max(res, cnt);
		} else {
			cnt = 1;	
			init = 1;
		}
	}

	cnt = 0;
	init = 1;
	for(int i = n - 1; i >= 0; i--) {
		if(values[i] >= init)	 {
			cnt++;	
			res = max(res, cnt);
		} else {
			cnt = 1;	
			init = 1;
		}
	}

	debug(res);

	int max_;

	if(res % 2 == 1) {
		max_ = res / 2 + 1;	
	} else {
		max_ = res / 2;
	}

	cout << max_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
