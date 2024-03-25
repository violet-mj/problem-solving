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
	lint n, f, a, b;		
	cin >> n >> f >> a >> b;
	vector<lint> m(n);
	for(lint i = 0; i < n; i++) cin >> m[i];

	lint init = 0;
	lint charge = f;

	for(lint i = 0; i < n; i++) {
		lint remain = (m[i] - init) * a;
		lint total = min(remain, b);

		if(charge - total > 0) {
			init = m[i];
			charge -= total;
		} else {
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
