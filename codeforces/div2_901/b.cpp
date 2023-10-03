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
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> ai(n);
	vector<int> bi(m);

	for(int i = 0; i < n; i++) cin >> ai[i];
	for(int i = 0; i < m; i++) cin >> bi[i];
	
	sort(all(ai));
	sort(all(bi));

	lint res = 0;
	if(bi[m-1] < ai[0]) {
		debug(ai);
		if(k % 2 == 0) {
			bi[0] ^= ai[n-1];
			ai[n-1] ^= bi[0];
			bi[0] ^= ai[n-1];
		} 

		debug(ai);
		for(int i = 0; i < n; i++) {
			res += ai[i];
		}
	} else {
		debug(ai);
		ai[0] ^= bi[m-1];
		bi[m-1] ^= ai[0];
		ai[0] ^= bi[m-1];
		sort(all(ai));
		sort(all(bi));
		debug(ai);
		if(k % 2 == 0) {
			bi[0] ^= ai[n-1];
			ai[n-1] ^= bi[0];
			bi[0] ^= ai[n-1];
		} 
		debug(ai);
		for(int i = 0; i < n; i++) {
			res += ai[i];
		}
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
