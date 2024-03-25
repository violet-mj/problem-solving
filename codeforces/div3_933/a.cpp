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
	int n, m, k; cin >> n >> m >> k;
	vector<int> bi(n);
	vector<int> ci(m);
	for(int i = 0; i < n; i++) cin >> bi[i];
	for(int i = 0; i < m; i++) cin >> ci[i];
	int cnt = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)	 {
			if(bi[i] + ci[j] <= k) cnt++;
		}
	}

	cout << cnt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
