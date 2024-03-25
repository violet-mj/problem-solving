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

lint mul(lint a, lint b) {
	if(b == 0) return 1;
	lint mid = mul(a, b/2);
	lint midMul = mid * mid;
	return b % 2 == 1 ? midMul * a : midMul;
}

void solve() {
	lint a, b, l;
	cin >> a >> b >> l;

	vector<lint> aa(1, 1LL);
	vector<lint> bb(1, 1LL);

	for(int i = 1; i <= 20; i++) {
		if(aa[i - 1] * a > 1000000LL) break;
		aa.pb(aa[i - 1] * a);
	}
	for(int i = 1; i <= 20; i++) {
		if(bb[i - 1] * b > 1000000LL) break;
		bb.pb(bb[i - 1] * b);
	}

	set<lint> cnt;

	debug(aa, bb);
	for(int x = 0; x < aa.size(); x++) {
		for(int y = 0; y < bb.size(); y++) {
			if(l % (aa[x] * bb[y]) == 0LL)	 {
				// debug(a, b, l, x, aa[x], y, bb[y]);
				lint divider = l / (aa[x] * bb[y]);
				cnt.insert(divider);
			}
		}
	}

	cout << cnt.size() << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
