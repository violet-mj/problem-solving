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

void solve() {
	int k, n;
	cin >> n >> k;
	vector<lint> value(n+1,0);
	vector<lint> prefixSum(n+1,0);
	priority_queue<lint> pq;
	for(int i = 1; i <= n; i++) {
		cin >> value[i];
		prefixSum[i] = prefixSum[i-1] + value[i];
		pq.push(prefixSum[i]);
	}
	lint res = 0;
	for(int i = 0; i < k; i++) {
		res += pq.top();
		pq.pop();
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
