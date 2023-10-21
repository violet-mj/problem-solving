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
	int n;
	cin >> n;

	vector<int> w(n);
	for(int i = 0; i < n; i++) cin >> w[i];

	int left = w[0];
	int right = w[1];

	for(int i = 2; i < n; i++) {
		if(left == right) {
			left += w[i];
		}	else {
			if(left < right) {
				left += w[i];
			} else {
				right += w[i];
			}
		}
	}

	int diff = abs(left - right);

	vector<int> pre {100,50,20,10,5,2,1};
	int res = 0;
	for(auto p: pre) {
		int tmp = diff / p;
		res += tmp;
		diff -= tmp * p;
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
