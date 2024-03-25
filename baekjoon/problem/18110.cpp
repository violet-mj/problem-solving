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


int round(int a, int b) {		
	int div100 = a % b;
	int thr = (b + 1)  / 2;
	a -= div100;
	a = div100 >= thr ? a + b : a;
	return a / b;
};

void solve() {
	int n; cin >> n;		
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(all(v));
	int p15 = round(n * 15, 100);
	int s = 0;
	for(int i = p15; i < n - p15; i++) {
		s+=v[i];
	}

	n -= 2 * p15;

	cout << round(s, n) << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
