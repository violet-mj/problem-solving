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
	int n;	cin >> n;
	vector<int> v(n);
	set<int> ss;
	set<int> ssr;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		ss.insert(i);
		ssr.insert(i);
	}

	vector<int> k(n, 0);
	vector<int> kr(n, 0);
	for(int i = 0; i < n; i++) {
		if(ss.find(v[i]) != ss.end()) ss.erase(v[i]);
		k[i] = *ss.begin();
	}

	for(int i = n - 1; i >= 0; i--) {
		if(ssr.find(v[i]) != ssr.end()) ssr.erase(v[i]);
		kr[i] = *ssr.begin();
	}

	debug(k, kr);
	for(int i = 0; i < n - 1; i++) {
		if(k[i] == kr[i + 1])	 {
			cout << 2 << "\n";
			cout << 1 << " " << i + 1 << "\n";
			cout << i + 2 << " " << n << "\n";
			return;
		}
	}
	cout << -1 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
