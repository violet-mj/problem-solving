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

lint n, x, y;

lint gcd(lint a, lint b) {
	while(b != 0) {
		a  = a % b;	
		swap(a, b);
	}
	return a;
}

void solve() {
	cin >> n >> x >> y;

	lint xc = n / x;
	lint yc = n / y;
	lint lcmV = (lint)x * (lint)y / (lint)gcd(x, y);
	lint lc = n / lcmV;

	lint res = 0;

	lint fc = xc - lc;
	lint sc = yc - lc;
	res += n * fc - fc * (fc - 1) / 2; 
	res -= sc * (sc + 1) / 2; 
		
	cout << res << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
