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

	int l = 0;
	int r = n;

	auto check = [&](int m) {
		int init = 1;
		int k = 1;
		for(int i = 0; i < n; i++) {
			if(values[i] >= init) {
				init += k;
			} else {
				init = 2;
				k = 1;
			}

			if(init == 0) return true;

			if(init > m + 1) {
				k = -1;	
				init = m;
			}
		}

		return false;		
	};

	while(l + 1 < r) {
		int mid = (l + r) >> 1;		
		if(check(mid)) {
			l = mid;	
		} else {
			r = mid;	
		}
	}

	cout << l + 1 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
