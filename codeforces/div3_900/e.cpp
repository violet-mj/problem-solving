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

int minInit(vector<int>& minTree, vector<int>& values, int node, int start, int end) {
	//debug(node, start, end);
	if(start == end) {
		return minTree[node] = values[start];
	} else {
		int mid = (start + end) >> 1;
		return minTree[node] = minInit(minTree, values, node * 2 + 1, start, mid) & minInit(minTree, values, node * 2 + 2, mid + 1, end);
	}
}

int minQuery(vector<int>& minTree, int node, int start, int end, int left, int right) {
	if(start > right || end < left) return 2147483647;
	if(start >= left && end <= right) return minTree[node];
	int mid = (start + end) >> 1;
	return minQuery(minTree, node * 2 + 1, start, mid, left, right) & minQuery(minTree, node * 2 + 2, mid + 1, end, left, right);
}

int minUpdate(vector<int>& minTree, int node, int index, int start, int end, int value) {
	if(index < start || index > end) return minTree[node];
	if(start == end) return minTree[node] = value;
	int mid = (start + end) >> 1;
	return minTree[node] = minUpdate(minTree, node * 2 + 1, index, start, mid, value) & minUpdate(minTree, node * 2 + 2, index, mid + 1, end, value);
}


void solve() {
	int n, q, l, k; 
	cin >> n;
	vector<int> values(n, 0);
	for(int i = 0; i < n; i++) cin >> values[i];
	vector<int> minTree(4 * n, 0);
	minInit(minTree, values, 0, 0, n - 1);
	
	cin >> q;

	for(int i = 0; i < q; i++) {
		cin >> l >> k;
		int lv = l-1;
		int rv = n;
		if(values[l-1] < k) {
			cout << -1 << " ";
			continue;
		}
		while(lv + 1 < rv) {
			int mid = (lv + rv) >> 1;
			int midValue = minQuery(minTree, 0, 0, n - 1, l-1, mid);

			if(midValue >= k) {
				lv = mid;	
			} else {
				rv = mid;	
			}
		}
		cout << lv + 1 << " ";
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
