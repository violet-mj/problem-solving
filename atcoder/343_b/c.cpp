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

bool check(lint x) {
	vector<int> k;
	while(x != 0) {
		k.pb(x % 10LL);
		x /= 10LL;
	}
	reverse(all(k));
	int nn = k.size();

	for(int i = 0; i < nn / 2; i++) {
		if(k[i] != k[nn - i - 1]) {
			return false;	
		}
	}
	return true;
}

void solve() {
	lint n; cin >> n;
	lint k = 0;
	for(int i = 1; i <= 1000000; i++) {
		if((lint) i * i * i > n) break;
		if(check((lint)i * i * i)) {
			k = (lint) i * i * i;			
		}
	}

	cout << k << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
