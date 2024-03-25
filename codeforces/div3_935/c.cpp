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
	string s; cin >> s;
	int sn = s.size();

	vector<int> v(sn + 1, 0);
	vector<int> vr(sn + 1, 0);

	for(int i = 1; i <= sn; i++) {
		v[i] = s[i - 1]  - '0';
		vr[i] = (s[i - 1] - '0') ^ 1;
	}

	vector<int> pv(sn + 1, 0);
	vector<int> pvr(sn + 1, 0);

	for(int i = 1; i <= sn; i++) {
		pv[i]	= pv[i - 1] + v[i];
		pvr[i] = pvr[i - 1] + vr[i];
	}

	double k = 600000;
	int res = -1;

	for(int i = 0; i <= sn; i++) {
		if(pvr[i] >= (i + 1) / 2 && pv[sn] - pv[i] >= (n - i + 1) / 2) {
			if(abs((double)n / 2 - i) < k) {
				k = abs((double)n / 2 - i);
				res = i;
			}
		}
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
