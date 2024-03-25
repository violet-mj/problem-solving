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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> A(n); set<int> As;
	vector<int> B(m); set<int> Bs;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
		As.insert(A[i]);
	}

	for(int i = 0; i < m; i++) {
		cin >> B[i];
		Bs.insert(B[i]);
	}

	vector<int> AA;
	vector<int> BB;
	vector<int> CC;

	for(auto i = As.begin(); i != As.end(); i++) {
		if(Bs.find(*i) == Bs.end() && *i >= 1 && *i <= k) {
			AA.pb(*i);
		}

		if(Bs.find(*i) != Bs.end() && *i >= 1 && *i <= k) {
			CC.pb(*i);
		}
	}

	for(auto i = Bs.begin(); i != Bs.end(); i++) {
		if(As.find(*i) == As.end() && *i >= 1 && *i <= k) {
			BB.pb(*i);
		}
	}

	debug(AA, BB, CC);
	int Amax = min((int)k / 2, (int)AA.size());
	int Bmax = min((int)k / 2, (int)BB.size());

	if(k - Amax - Bmax <= CC.size()) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
