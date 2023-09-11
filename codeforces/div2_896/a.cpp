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
int n;
void solve() {
	cin >> n;
	vector<int> v(n, 0);
	int k = 0;
	for(int i = 0; i < n; i++) {
		cin >> v[i];	
		k ^= v[i];
	}

	if(k == 0) {
		cout << 1 << "\n"	;
		cout << 1 << " " << n << "\n";
	} else {
		if(n % 2 == 0) {
			cout << 2 << "\n";
			cout << 1 << " " << n << "\n";
			cout << 1 << " " << n << "\n";
		} else {
			cout << 4 << "\n";
			cout << 1 << " " << n << "\n";
			cout << 1 << " " << n - 1 << "\n";
			cout << n - 1 << " " << n << "\n";
			cout << n - 1 << " " << n << "\n";
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
