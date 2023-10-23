
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

void solve() {
	int n, k;	
	cin >> n >> k;
	vector<int> values(n);
	int min_ = k;
	for(int i = 0; i < n; i++) {
		cin >> values[i];
		if(values[i] % k == 0) {
			min_ = 0;	
		} else {
			min_ = min(min_, (k - values[i] % k));
		}
	}

	if(k == 4 && n > 1) {
		vector<int> tmp(n, 0);

		for(int i = 0; i < n; i++) {
			if(values[i] % 2 == 0)	 {
				tmp[i] = 0;	
			} else {
				tmp[i] = 1;
			}
		}
		
		sort(all(tmp));
		min_ = min(tmp[0] + tmp[1], min_);
	}

	cout << min_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
		solve();
}

