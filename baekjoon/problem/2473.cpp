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
	int n;		
	cin >> n;
	vector<lint> v(n);
	lint maxk = 1LL << 60;
	vector<lint> res;
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(all(v));

	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++)	 {
			lint ts = -(v[i] + v[j]);
			int l = j + 1;
			int r = n - 1;
			if(l > r) continue;
			while(l + 1 < r) {
				int mid = (l + r) >> 1;
				if(v[mid] < ts) {
					l = mid;	
				} else {
					r = mid;	
				}
			}
			debug(i, j, l, r);
			lint ss1 = abs(v[i] + v[j] + v[l]);
			lint ss2 = abs(v[i] + v[j] + v[r]);
			lint ss = min(ss1, ss2);
			if(abs(ss) < maxk) {
					maxk = abs(ss);	
					if(ss1 < ss2) {
						res = {v[i], v[j], v[l]};
					} else {
						res = {v[i], v[j], v[r]};
					}
			}
		}
	}

	for(auto i: res) {
		cout << i << " ";	
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
