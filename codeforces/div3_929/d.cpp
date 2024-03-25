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

int gcd(int a, int b) {
	while(b != 0) {
		a = a % b;	
		swap(a, b);
	}
	return a;
}

void solve() {
	int n; cin >> n;			
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(all(v));
	if(v[0] != v[1]) {
		cout << "YES\n";
		return;
	}

	for(int i = 2; i < n; i++) {
		if(v[i] % v[0] != v[1] && v[i] % v[0] != 0) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
