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
	lint n, q; cin >> n >> q;
	lint rs = n * (n + 1) / 2;
	lint cs = n * (n + 1) / 2;
	lint rc = n;
	lint cc = n;
	vector<int> vr(n + 1, 0);
	vector<int> vc(n + 1, 0);

	for(int i = 0; i < q; i++) {
		char cmd;	
		int num;
		cin >> cmd >> num;

		if(cmd == 'R') {
			if(vr[num]) {
				cout << 0 << "\n";
				continue;
			}
			cout << cs + cc * num << "\n";
			rs -= num;
			rc--;
			vr[num] = 1;
		} else {
			if(vc[num]) {
				cout << 0 << "\n";
				continue;
			}
			cout << rs + rc * num << "\n";
			cs -= num;
			cc--;
			vc[num] = 1;
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
