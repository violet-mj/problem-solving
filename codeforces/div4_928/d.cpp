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
	int n; cin >> n;		
	vector<int> v(n);
	map<int, int> check;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		check[v[i]]++;
	}
	debug(check);

	int cnt = 0;
	const lint fullBit = (1LL << 31) - 1LL;
	debug(fullBit);
	for(int i = 0; i < n; i++) {
		if(check[v[i] ^ fullBit]-- > 0) {
			cnt++;	
		}
	}

	cout << n - cnt / 2 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
