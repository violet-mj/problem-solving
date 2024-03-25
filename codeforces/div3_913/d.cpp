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
	vector<pii> lrs(n);

	for(int i = 0; i < n; i++) {
		cin >> lrs[i].f >> lrs[i].s;
	}

	auto check = [&](int ck) {
		int initl = -ck;		
		int initr = ck;

		for(int i = 0; i < n; i++) {
			if(initl > lrs[i].s || initr < lrs[i].f) return false;
			if(initr > lrs[i].s) {
				initr = lrs[i].s;
			}

			if(initl < lrs[i].f) {
				initl = lrs[i].f;	
			}
			initl -= ck;
			initr += ck;
		}

		return true;
	};

	int l = -1;	
	int r = 1e9;

	while(l + 1 < r) {
		int mid = (l + r)	>> 1;
		
		if(check(mid)) {
			r = mid;	
		} else {
			l = mid;	
		}
	}

	cout << r << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
