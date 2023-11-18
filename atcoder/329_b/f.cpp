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
	int n, q;
	cin >> n >> q;
	vector<int> values(n);
	set<int> sets[200000];
	vector<int> mapping(n);

	for(int i = 0; i < n; i++) {
		cin >> values[i];
		sets[i].insert(values[i]);
		mapping[i] = i;
	}

	int a, b;
	for(int i = 0; i < q; i++) {
		cin >> a >> b;		
		a--; b--;
		int ma = mapping[a];
		int mb = mapping[b];
		if(sets[ma].size() > sets[mb].size()) {
			for(auto i = sets[mb].begin(); i != sets[mb].end(); i++) {
				sets[ma].insert(*i);
			}
			cout << sets[ma].size() << "\n";
			sets[mb].clear();
			swap(mapping[a], mapping[b]);
		} else {
			for(auto i = sets[ma].begin(); i != sets[ma].end(); i++) {
				sets[mb].insert(*i);
			}
			sets[ma].clear();
			cout << sets[mb].size() << "\n";
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
