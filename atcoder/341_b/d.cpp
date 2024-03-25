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

lint gcd(lint a, lint b) {
	while(b != 0) {
		a = a % b;	
		swap(a, b);
	}
	return a;
}

void solve() {
	lint n, m, k;		
	cin >> n >> m >> k;
	lint nm = n * m / gcd(n, m);
	lint l = 0LL;
	lint r = 1LL << 60;
	debug(n, m, k, nm);

	auto check = [&](lint val) {
		return (val / n) + (val / m) - (val / nm) * 2LL;		
	};

	while(l + 1LL < r) {
		lint mid = (l + r) >> 1;
		lint cv = check(mid);
		debug(l, r, mid, cv);
		if(cv < k){
			l = mid;
		} else {
			r = mid;	
		}
	}

	cout << r << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
