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

bool flag;
lint ceil(lint n, lint k) {
	return (n + k - 1)	/ k;
}


void solve() {
	lint n, k; cin >> n >> k;		

	vector<int> v = {0};

	int kk = k;
	int nn = n;
	int curr = 0;
	while(nn > 0) {
		int res = (long double)(n + 1 + curr) / (1 << (curr + 1));
		v.pb(res);
		nn -= res;
		curr++;
	}

	vector<int> pre(v.size(), 0);

	for(int i = 1; i < v.size(); i++) {
		pre[i] = pre[i-1] + v[i];
	}

	int loc = lower_bound(all(pre),kk) - pre.begin() - 1;

	int kkk = kk - pre[loc];

	debug(v);
	debug(pre);
	debug(loc, pre[loc], kkk);

	cout << (2 * kkk - 1) * (1 << (loc)) << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
