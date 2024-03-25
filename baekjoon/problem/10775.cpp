#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

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
	int g, p;	cin >> g >> p;
	set<int> ss;
	vector<int> ap(p);

	for(int i = 0; i <= g; i++) {
		ss.insert(i);
	}

	for(int i = 0; i < p; i++) {
		cin >> ap[i];
	}

	for(int i = 0; i < p; i++) {
		int curr = lower_bound(all(ss), ap[i]);
		debug(curr, ss);
		if(curr == 0 || curr > ap[i]) {
			cout << i << "\n";	
			return;
		} else {
			ss.erase(curr);
		}
	}
	cout << p << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
