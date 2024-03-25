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
	int nn; cin >> nn;
	vector<int> v;
	set<int> vs;
	for(int i = 0; i < nn; i++) {
		int tmp; cin >> tmp;
		if(vs.find(tmp) != vs.end()) continue;
		v.pb(tmp);
		vs.insert(tmp);
	}
	sort(all(v));
	reverse(all(v));

	int n = v.size();

	int l = 0; 
	int r = 0;
	int cnt = 1;
	int res = 1;

	while(l <= r && r < n) {
		if(l == r) {
			r++;	
			continue;
		}
		if(v[l] - v[r] < nn) {
			res = max(res, r - l + 1);
			r++;
		} else {
			while(v[l] - v[r] >= nn && l < r) {
				l++;	
			}
		}
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
