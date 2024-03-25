
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
	vector<int> A(n);
	for(int i = 0; i < n; i++) cin >> A[i];
	int m; cin >> m;
	vector<int> B(m);
	for(int i = 0; i < m; i++) cin >> B[i];
	int l; cin >> l;
	vector<int> C(l);
	for(int i = 0; i < l; i++) cin >> C[i];
	int q; cin >> q;
	vector<int> X(q);
	for(int i = 0; i < q; i++) cin >> X[i];

	set<int> check;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)	 {
			for(int z = 0; z < l; z++)	 {
				check.insert(A[i] + B[j] + C[z]);
			}
		}
	}

	for(int i = 0; i < q; i++) {
		if(check.find(X[i]) != check.end())	 {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
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
