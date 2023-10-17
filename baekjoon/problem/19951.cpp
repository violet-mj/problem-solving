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
	int n, m, a, b, k;	
	cin >> n >> m;

	vector<int> yeon(n + 2, 0);
	vector<int> pre(n + 2, 0);
	vector<int> preSum(n + 2, 0);

	for(int i = 1; i <= n; i++) cin >> yeon[i];

	for(int i = 0; i < m; i++) {
		cin >> a >> b >> k;	
		pre[a]+=k;
		pre[b+1]-=k;
	}

	for(int i = 1; i <= n; i++)  {
		preSum[i] = preSum[i-1] + pre[i];
	}

	for(int i = 1; i <= n; i++) {
		cout << yeon[i] + preSum[i]	<< " \n"[i == n];
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
