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
typedef pair<lint, lint> pii;
typedef pair<lint, lint> pll;
typedef vector<lint> vi;
typedef vector<lint> vl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

lint n, q, cmd, x, y, c, va;
vector<lint> values;
vector<lint> tree;
vector<lint> mos;

lint query(lint node, lint start, lint end, lint left, lint right) {
	if(start > right || end < left) return 0;
	if(start >= left && end <= right) return tree[node];
	lint mid = (start + end) >> 1;
	return query(node * 2 + 1, start, mid, left, right)	+ query(node * 2 + 2, mid + 1, end, left, right);
}

lint update(lint node, lint index, lint left, lint right, lint diff) {
	if(index < left || index > right) return tree[node];
	if(left == right) {
		mos[index] = mos[index] + diff;
		return tree[node] = mos[index];
	}
	lint mid = (left + right) >> 1;
	return tree[node] = update(node * 2 + 1, index, left, mid, diff)	+ update(node * 2 + 2, index, mid + 1, right, diff);
}


void solve() {
	cin >> n;
	values.resize(n+1, 0);
	mos.resize(n+1, 0);
	tree.resize(4 * (n+1), 0);
	for(lint i = 0; i < n; i++) cin >> values[i];
	cin >> q;
	for(lint i = 0;i < q; i++) {
		cin >> cmd;	
		if(cmd == 1) {
			cin >> x >> y >> c;	
			update(0, x-1, 0, n, c);
			update(0, y, 0, n, -c);
			debug(tree);
			debug(mos);
		} else {
			cin >> va;
			lint res = query(0, 0, n, 0, va - 1);
			cout << values[va-1] + res << "\n";
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	lint t;
	// cin >> t;
	// for(lint i = 0; i < t; i++) 
	solve();
	return 0;
}
