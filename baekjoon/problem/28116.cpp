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
	vector<int> v(n + 1, 0);
	vector<lint> res(n + 1, 0);
	vector<int> pos(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		pos[v[i]] = i;
	}

	for(int i = 1; i <= n; i++) {
		int iPos = pos[i];
		int iValue = v[i];
		int diff = abs(iPos - i);
		res[iValue] += diff;
		res[i] += diff;
		swap(v[i], v[iPos]);
		swap(pos[iValue], pos[i]);
	}

	for(int i = 1; i <= n; i++) {
		cout << res[i] << " \n"[i == n];
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
