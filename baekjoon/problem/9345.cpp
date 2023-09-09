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

int n, k, cmd, x, y;

int minInit(vector<int>& minTree, vector<int>& values, int node, int start, int end) {
	//debug(node, start, end);
	if(start == end) {
		return minTree[node] = values[start];
	} else {
		int mid = (start + end) >> 1;
		return minTree[node] = min(minInit(minTree, values, node * 2 + 1, start, mid), minInit(minTree, values, node * 2 + 2, mid + 1, end));
	}
}

int maxInit(vector<int>& maxTree, vector<int>& values, int node, int start, int end) {
	//debug(node, start, end);
	if(start == end) {
		return maxTree[node] = values[start];
	} else {
		int mid = (start + end) >> 1;
		return maxTree[node] = max(maxInit(maxTree, values ,node * 2 + 1, start, mid), maxInit(maxTree, values,node * 2 + 2, mid + 1, end));
	}
}

int minQuery(vector<int>& minTree, int node, int start, int end, int left, int right) {
	if(start > right || end < left) return 1000000000;
	if(start >= left && end <= right) return minTree[node];
	int mid = (start + end) >> 1;
	return min(minQuery(minTree, node * 2 + 1, start, mid, left, right), minQuery(minTree, node * 2 + 2, mid + 1, end, left, right));
}

int maxQuery(vector<int>& maxTree, int node, int start, int end, int left, int right) {
	if(start > right || end < left) return 0;
	if(start >= left && end <= right) return maxTree[node];
	int mid = (start + end) >> 1;
	return max(maxQuery(maxTree, node * 2 + 1, start, mid,left, right), maxQuery(maxTree, node * 2 + 2, mid + 1, end, left, right));
}

int minUpdate(vector<int>& minTree, int node, int index, int start, int end, int value) {
	if(index < start || index > end) return minTree[node];			
	if(start == end) return minTree[node] = value; 
	int mid = (start + end) >> 1;
	return minTree[node] = min(minUpdate(minTree, node * 2 + 1, index, start, mid, value), minUpdate(minTree, node * 2 + 2, index, mid + 1, end, value));
}

int maxUpdate(vector<int>& maxTree, int node, int index, int start, int end, int value) {
	if(index < start || index > end) return maxTree[node];			
	if(start == end) return maxTree[node] = value; 
	int mid = (start + end) >> 1;
	return maxTree[node] = max(maxUpdate(maxTree, node * 2 + 1, index, start, mid, value), maxUpdate(maxTree, node * 2 + 2, index, mid + 1, end, value));
}
void solve() {
	cin >> n >> k;	
	vector<int> minTree(4 * n, 0);
	vector<int> maxTree(4 * n, 0);
	vector<int> values(n , 0);
	for(int i = 0; i < n; i++) {
		values[i] = i;	
	}
	minInit(minTree, values,0, 0, n - 1);
	maxInit(maxTree, values,0, 0, n - 1);
	for(int i = 0; i < k; i++) {
		cin >> cmd >> x >> y;	

		if(cmd == 0) {
			minUpdate(minTree, 0, x, 0, n - 1, values[y]);
			minUpdate(minTree, 0, y, 0, n - 1, values[x]);
			maxUpdate(maxTree, 0, x, 0, n - 1, values[y]);
			maxUpdate(maxTree, 0, y, 0, n - 1, values[x]);
			swap(values[x], values[y]);
		} else {
			int minValue = minQuery(minTree, 0, 0, n - 1, x, y);
			int maxValue = maxQuery(maxTree, 0, 0, n - 1, x, y);
			if(x == minValue && y == maxValue) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
