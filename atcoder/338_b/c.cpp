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
	lint n; cin >> n;
	vector<lint> qi(n);
	vector<lint> ai(n);
	vector<lint> bi(n);

	for(int i = 0; i < n; i++) cin >> qi[i];
	for(int i = 0; i < n; i++) cin >> ai[i];
	for(int i = 0; i < n; i++) cin >> bi[i];

	lint res = 0;

	for(lint i = 0; i <= 1000000; i++) {
		lint min_ = 1e18;
		for(lint j = 0; j < n; j++) {
			if(bi[j] == 0) {
				continue;	
			}
			min_ = min(min_, (qi[j] - ai[j] * i) / bi[j]);
		}

		bool flag = true;

		for(lint j = 0; j < n; j++) {
			if(ai[j] * i + bi[j] * min_ > qi[j]) {
				flag = false;	
				break;
			}
		}

		if(min_ >= 0 && flag) {
			res = max(res, i + min_);
		}
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
