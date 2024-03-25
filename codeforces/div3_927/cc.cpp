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

int n, MOD;

vector<int> tree;
vector<int> values;
int init(int node, int left, int right) {
	if(left == right) {
		return tree[node] = values[left] % MOD;
	}	else {
		return tree[node] = (lint)init(node * 2 + 1, left, (left + right) / 2) * (lint)init(node * 2 + 2, (left + right) / 2 + 1, right) % MOD;
	}
}

int mul(int node, int start, int end, int left, int right) {
	if(right < start || left > end) return 1;
	if(left <= start && right >= end) {
		return tree[node] % MOD;
	} 
	int mid = (start + end) / 2;
	return (lint)mul(2 * node + 1, start, mid, left, right) * (lint)mul(2 * node + 2, mid + 1, end, left, right) % MOD;
}

int update(int node, int start, int end, int index) {
	if(index < start || index > end) return tree[node];
	if(start == end) return tree[node] = values[index];
	int mid = (start + end) / 2;	
	return tree[node] = (lint)update(node * 2 + 1, start, mid, index) * (lint)update(node * 2 + 2, mid + 1, end, index) % MOD;
}

void solve() {
	string s;
	cin >> n >> MOD;
	values.assign(n, 0);tree.assign(4 * n, 0);
	for(int i = 0; i < n; i++) {
		cin >> values[i];
	}
	cin >> s;
	init(0, 0, n - 1);

	int l = 0;
	int r = n - 1;
	debug(values);

	for(int i = 0; i < n; i++) {
		cout << mul(0, 0, n - 1, l, r) << " ";
		if(s[i] == 'L') {
			l++;
		} else {
			r--;	
		}
	}

	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	solve();
}
