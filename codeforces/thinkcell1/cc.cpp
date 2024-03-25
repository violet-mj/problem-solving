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
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define all(v) (v).begin(),(v).end()

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	set<int> res;
	vector<int> check;
	set<int> exist;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		check.pb(v[i] + i + 1);
	}
	compress(check);
	int nn = check.size();
	for(int i = nn - 1; i >= 0; i--) {
		cout << check[i] << " \n"[i == nn - 1];
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
