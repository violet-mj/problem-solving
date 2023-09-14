#include <iostream>
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

int n;

void solve() {
	cin >> n;	
	vector<int> values(n);
	int m = 0;
	int bigger = 0;
	for(int i = 0; i < n; i++) {
		cin >> values[i];
		m += values[i];
	}
	int avg = m / n;
	int rem = m % n;
	int res = 0;
	int res2 = 0;

	for(int i = 0; i < n; i++) {
		if(values[i] < avg)	 {
			res += avg - values[i];
		}

		if(values[i] > avg + 1) {
			res2 += values[i]	- avg - 1;
		}
	}

	cout << max(res, res2) << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
