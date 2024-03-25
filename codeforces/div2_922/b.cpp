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
	vector<int> a(n);
	vector<int> b(n);
	vector<pii> c(n);

	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	for(int i = 0; i < n; i++) {
		c[i] = mp(a[i], b[i]);
	}

	sort(all(c), [](pii p1, pii p2) {
		return p1.f < p2.f;
	});

	for(int i = 0; i < n; i++) {
		cout << c[i].f << " \n"[i == n - 1];	
	}
	for(int i = 0; i < n; i++) {
		cout << c[i].s << " \n"[i == n - 1];	
	}

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
